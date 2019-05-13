#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <chrono>
#include <condition_variable>
 
std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;
 
void worker_thread()
{
    std::cout << "begin this thread" << std::endl;
    // Wait until main() sends data
    std::unique_lock<std::mutex> lk(m);
    std::cout << "after lk(m) in worker_thread" << std::endl;
    cv.wait(lk, []{return ready;});
 
    // after the wait, we own the lock.
    std::cout << "Worker thread is processing data\n";
    data += " after processing";
 
    // Send data back to main()
    processed = true;
    std::cout << "Worker thread signals data processing completed\n";
 
    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    lk.unlock();
    cv.notify_one();
}
 
int main()
{
    std::thread worker(worker_thread);
    std::this_thread::sleep_for(std::chrono::seconds(10));
    
    // std::unique_ptr<std::thread> new_thread;
    // new_thread.reset(new std::thread([]{
    //     int i = 0;
    //     while (true) {
    //         std::cout << "running " << i++ << std::endl;
    //         std::this_thread::sleep_for(std::chrono::milliseconds(10));
    //     }
    // }));

    // std::this_thread::sleep_for(std::chrono::seconds(10));

    // if (new_thread != nullptr && new_thread->joinable()) {
    //   new_thread->join();
    // }
 
    data = "Example data";
    // send data to the worker thread
    {
        std::lock_guard<std::mutex> lk(m);
        std::cout << "after lk(m) in main" << std::endl;
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }


    cv.notify_one();
 
    // wait for the worker
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, []{return processed;});
    }
    std::cout << "Back in main(), data = " << data << '\n';
 
    worker.join();
}