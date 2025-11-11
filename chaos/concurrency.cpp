#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>
#include <chrono>
#include <random>

// Global variables for demonstration
std::mutex print_mutex;
std::atomic<int> atomic_counter{0};
int regular_counter = 0;
std::mutex counter_mutex;

// Function to demonstrate thread creation and basic synchronization
void worker_function(int id, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        // Thread-safe printing using mutex
        {
            std::lock_guard<std::mutex> lock(print_mutex);
            std::cout << "Thread " << id << " iteration " << i << std::endl;
        }
        
        // Simulate some work
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

// Function to demonstrate atomic operations
void atomic_worker(int id, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        // Atomic increment - thread-safe without locks
        atomic_counter.fetch_add(1);
        
        // Atomic operations are lock-free and very fast
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

// Function to demonstrate mutex-protected operations
void mutex_worker(int id, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        // Mutex-protected increment
        {
            std::lock_guard<std::mutex> lock(counter_mutex);
            regular_counter++;
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

// Function to demonstrate race conditions (unsafe)
void unsafe_worker(int id, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        // This is NOT thread-safe - will cause race conditions
        regular_counter++;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

// Producer-Consumer example with mutex
class ProducerConsumer {
private:
    std::vector<int> buffer;
    std::mutex buffer_mutex;
    std::atomic<bool> done{false};
    static const int MAX_BUFFER_SIZE = 10;

public:
    void producer() {
        for (int i = 0; i < 20; ++i) {
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            
            {
                std::lock_guard<std::mutex> lock(buffer_mutex);
                if (buffer.size() < MAX_BUFFER_SIZE) {
                    buffer.push_back(i);
                    std::cout << "Produced: " << i << " (buffer size: " << buffer.size() << ")" << std::endl;
                }
            }
        }
        done = true;
    }
    
    void consumer() {
        while (!done || !buffer.empty()) {
            std::this_thread::sleep_for(std::chrono::milliseconds(30));
            
            {
                std::lock_guard<std::mutex> lock(buffer_mutex);
                if (!buffer.empty()) {
                    int value = buffer.back();
                    buffer.pop_back();
                    std::cout << "Consumed: " << value << " (buffer size: " << buffer.size() << ")" << std::endl;
                }
            }
        }
    }
};

// Atomic operations demonstration
void atomic_operations_demo() {
    std::cout << "\n=== Atomic Operations Demo ===" << std::endl;
    
    std::atomic<int> atomic_int{0};
    
    // Basic atomic operations
    std::cout << "Initial value: " << atomic_int.load() << std::endl;
    
    atomic_int.store(42);
    std::cout << "After store(42): " << atomic_int.load() << std::endl;
    
    int old_value = atomic_int.exchange(100);
    std::cout << "After exchange(100), old value was: " << old_value << std::endl;
    std::cout << "Current value: " << atomic_int.load() << std::endl;
    
    // Compare and swap
    int expected = 100;
    bool success = atomic_int.compare_exchange_strong(expected, 200);
    std::cout << "Compare and swap (100 -> 200): " << (success ? "success" : "failed") << std::endl;
    std::cout << "Current value: " << atomic_int.load() << std::endl;
    
    // Fetch and add
    int result = atomic_int.fetch_add(10);
    std::cout << "fetch_add(10) returned: " << result << ", current value: " << atomic_int.load() << std::endl;
}

int main() {
    std::cout << "=== C++ Concurrency Examples ===" << std::endl;
    
    // 1. Basic thread creation and joining
    std::cout << "\n1. Basic Thread Creation:" << std::endl;
    std::thread t1(worker_function, 1, 3);
    std::thread t2(worker_function, 2, 3);
    
    t1.join();
    t2.join();
    
    // 2. Atomic vs Mutex performance comparison
    std::cout << "\n2. Atomic vs Mutex Performance:" << std::endl;
    
    const int iterations = 1000;
    const int num_threads = 4;
    
    // Reset counters
    atomic_counter = 0;
    regular_counter = 0;
    
    // Test atomic operations
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::thread> atomic_threads;
    for (int i = 0; i < num_threads; ++i) {
        atomic_threads.emplace_back(atomic_worker, i, iterations);
    }
    for (auto& t : atomic_threads) {
        t.join();
    }
    auto atomic_time = std::chrono::high_resolution_clock::now() - start;
    
    // Test mutex operations
    start = std::chrono::high_resolution_clock::now();
    std::vector<std::thread> mutex_threads;
    for (int i = 0; i < num_threads; ++i) {
        mutex_threads.emplace_back(mutex_worker, i, iterations);
    }
    for (auto& t : mutex_threads) {
        t.join();
    }
    auto mutex_time = std::chrono::high_resolution_clock::now() - start;
    
    std::cout << "Atomic counter final value: " << atomic_counter.load() << std::endl;
    std::cout << "Mutex counter final value: " << regular_counter << std::endl;
    std::cout << "Atomic time: " << std::chrono::duration_cast<std::chrono::microseconds>(atomic_time).count() << " μs" << std::endl;
    std::cout << "Mutex time: " << std::chrono::duration_cast<std::chrono::microseconds>(mutex_time).count() << " μs" << std::endl;
    
    // 3. Producer-Consumer pattern
    std::cout << "\n3. Producer-Consumer Pattern:" << std::endl;
    ProducerConsumer pc;
    std::thread producer_thread(&ProducerConsumer::producer, &pc);
    std::thread consumer_thread(&ProducerConsumer::consumer, &pc);
    
    producer_thread.join();
    consumer_thread.join();
    
    // 4. Atomic operations demonstration
    atomic_operations_demo();
    
    // 5. Race condition demonstration (commented out for safety)
    std::cout << "\n5. Race Condition Warning:" << std::endl;
    std::cout << "Uncomment the unsafe_worker calls below to see race conditions!" << std::endl;
    std::cout << "Race conditions can cause:" << std::endl;
    std::cout << "- Incorrect final values" << std::endl;
    std::cout << "- Crashes or undefined behavior" << std::endl;
    std::cout << "- Non-deterministic results" << std::endl;
    
    /*
    // WARNING: This demonstrates race conditions - results will be unpredictable!
    regular_counter = 0;
    std::vector<std::thread> unsafe_threads;
    for (int i = 0; i < num_threads; ++i) {
        unsafe_threads.emplace_back(unsafe_worker, i, iterations);
    }
    for (auto& t : unsafe_threads) {
        t.join();
    }
    std::cout << "Unsafe counter final value: " << regular_counter << " (should be " << num_threads * iterations << ")" << std::endl;
    */
    
    std::cout << "\n=== Key Takeaways ===" << std::endl;
    std::cout << "1. std::thread: Create and manage threads" << std::endl;
    std::cout << "2. std::mutex: Protect shared data from race conditions" << std::endl;
    std::cout << "3. std::atomic: Lock-free operations for simple data types" << std::endl;
    std::cout << "4. Always use synchronization mechanisms for shared data" << std::endl;
    std::cout << "5. Atomic operations are generally faster than mutexes for simple operations" << std::endl;
    
    return 0;
}
