use std::time::Duration;

#[tokio::main]
async fn main() {
    let blocking_task = tokio::task::spawn_blocking(|| {
        std::thread::sleep(Duration::new(1, 0));
        println!("Hello, world from another thread!");
    });

    // blocking_task が最初に実行されるけど、
    // blocking_task のなかで 1 秒待つ処理があるので Hello が先に表示される
    println!("Hello");
    blocking_task.await.unwrap();
}
