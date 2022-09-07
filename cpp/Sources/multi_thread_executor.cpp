#include <array>
#include <functional>
#include <thread>
#include <chrono>
#include <iostream>
#include <queue>

class MultiTureadExecutor
{
public:
    MultiTureadExecutor() noexcept
        : m_Thread(std::thread(&MultiTureadExecutor::ExecuteQueue, this))
    {

    }
    
    void Submit(std::function<void()> func) noexcept {
        const auto currentIndex = GetCurrentIndex();
        m_Queues[currentIndex].push(func);
    }
    
    void ExecuteNextQueue() noexcept {
        m_Index = (++m_Index) % 2;
    }
    
    int GetCurrentIndex()const noexcept {
        return m_Index;
    }
    
private:
    void ExecuteQueue() noexcept {
        while (true) {
            std::lock_guard<std::mutex> lock{m_Mutex};
            
            auto* pQueue = &m_Queues[m_Index];
            while (!pQueue->empty()) {
                pQueue->front()();
                pQueue->pop();
            }
            
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
    
private:
    std::mutex m_Mutex;
    std::thread m_Thread;
    std::array<std::queue<std::function<void()>>, 2> m_Queues;
    std::condition_variable m_Condition;
    int m_Index = 0;
};

int main() {
    MultiTureadExecutor executor;
    
    int count = 0;
    while (true) {
        executor.Submit([](){
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << std::this_thread::get_id() << std::endl;
        });
        executor.Submit([](){
            std::cout << std::this_thread::get_id() << std::endl;
        });
        executor.ExecuteNextQueue();
        
        std::cout << std::this_thread::get_id() << ": " << count++  << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    
    return EXIT_SUCCESS;
}
