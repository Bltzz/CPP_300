/*
** EPITECH PROJECT, 2020
** cpp_rush3_threads_2019
** File description:
** ThreadManager
*/

#ifndef THREADMANAGER_HPP_
#define THREADMANAGER_HPP_

#include <thread>
#include <mutex>

/// ThreadManager
/// Open and close std::threads quickly
/// [usage]:
///     your thread function must take a ThreadManager at first parameter
class ThreadManager
{
    public:
        ThreadManager() = default;
        ~ThreadManager() { delete this->_thread; };

        bool isOpen() const { return this->_open; };
        void wait() const { while (!this->_started); };
        void go() { this->_started = true; };
        void start() { this->_thread->detach(); };
        void stop() { this->_open = false; };

        void setThread(std::thread *thread) { this->_thread = thread; };
        std::thread *getThread() const { return this->_thread; }; 
    private:
        bool _open = true;
        bool _started = false;
        std::thread *_thread = nullptr;
};

#endif /* !THREADMANAGER_HPP_ */