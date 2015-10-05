#include <mutex>
#include <thread>

extern "C"
{
    void do_thread_init(void* ptr)
    {
        // Supposed to init the thread lib, thus nothing to do
    }

    int do_thread_supported(void)
    {
        return 1;
    }

    void do_static_mutex_free(void* ptr)
    {
        delete reinterpret_cast<std::mutex*>(ptr);
    }

    void do_static_mutex_lock(void* ptr)
    {
        reinterpret_cast<std::mutex*>(ptr)->lock();
    }

    void do_static_mutex_unlock(void* ptr)
    {
        reinterpret_cast<std::mutex*>(ptr)->unlock();
    }

    void do_static_mutex_init(void* ptr)
    {
        ptr = new std::mutex;
    }

    void do_static_rec_mutex_free(void* ptr)
    {
        delete reinterpret_cast<std::recursive_mutex*>(ptr);
    }

    void do_static_rec_mutex_lock(void* ptr)
    {
        reinterpret_cast<std::recursive_mutex*>(ptr)->lock();
    }

    void do_static_rec_mutex_unlock(void* ptr)
    {
        reinterpret_cast<std::recursive_mutex*>(ptr)->unlock();
    }

    void do_static_rec_mutex_init(void* ptr)
    {
        ptr = new std::recursive_mutex;
    }

    void do_mutex_free(void* ptr)
    {

    }

    void do_mutex_lock(void* ptr)
    {

    }

    void do_mutex_unlock(void* ptr)
    {

    }

    // ==============================================


    void* new_fluid_cond_mutex(void)
    {
        // TODO FIX ME
        return 0;
    }


    void do_cond_free(void* cond)
    {

    }

    void do_cond_signal(void* cond)
    {

    }

    void do_cond_broadcast(void* cond)
    {

    }

    void do_cond_wait(void* cond, void* mutex)
    {

    }

    // ===============================================


    void *new_fluid_cond(void)
    {
        return 0;
    }

    void* do_static_private_get(void* ptr)
    {
        return 0;
    }

    void do_static_private_set(void* ptr, void* data, void* ptr2)
    {

    }

    void do_static_private_free(void* ptr)
    {

    }

    void do_static_private_init(void* ptr)
    {

    }

    int do_atomic_inc(volatile int* v)
    {
        return *++v;
    }

    int do_atomic_int_add(volatile int* i, volatile int v)
    {
        return *i + v;
    }

    int do_atomic_int_get(volatile void* ptr)
    {
        return *(int*)ptr;
    }

    void do_atomic_int_set(volatile void* ptr, volatile int v)
    {
        (*(int*)ptr) = v;
    }

    int do_atomic_int_exchange_and_add(volatile void* ptr, int v)
    {
        return v;
    }

    void* do_thread_self()
    {
        return std::this_thread;
    }

    int flud_atomic_int_get(int* ptr)
    {
        return *ptr;
    }

    /**
    * Join a thread (wait for it to terminate).
    * @param thread Thread to join
    * @return FLUID_OK
    */
    int
        fluid_thread_join(void* thread)
    {
        // TODO FIX ME

        reinterpret_cast<std::thread*>(thread)->join();
        //  g_thread_join (thread);

        //return FLUID_OK;
        return 0;
    }

    struct fluid_time
    {
        long tv_usec;
        long tv_sec;
    };

    void fluid_usleep(long v)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(v));
    }


    void fluid_get_current_time(struct fluid_time* ptr)
    {
        // TODO FIX ME
    }

    /**
    * Create a new thread.
    * @param func Function to execute in new thread context
    * @param data User defined data to pass to func
    * @param prio_level Priority level.  If greater than 0 then high priority scheduling will
    *   be used, with the given priority level (used by pthreads only).  0 uses normal scheduling.
    * @param detach If TRUE, 'join' does not work and the thread destroys itself when finished.
    * @return New thread pointer or NULL on error
    */
    typedef void(*fluid_thread_func_t)(void* data);

    void* new_fluid_thread(const char *name, fluid_thread_func_t func, void *data, int prio_level, int detach)
    {
        // TODO FIX ME

        std::thread* t = new std::thread(func, data);
        
        if (detach)
        {
            t->detach();
        }

        return t;

        /*
        GThread *thread;
        fluid_thread_info_t *info;
        GError *err = NULL;

        g_return_val_if_fail (func != NULL, NULL);

        #if OLD_GLIB_THREAD_API
        if (!g_thread_supported ()) g_thread_init (NULL);
        #endif

        if (prio_level > 0)
        {
        info = FLUID_NEW (fluid_thread_info_t);

        if (!info)
        {
        FLUID_LOG(FLUID_ERR, "Out of memory");
        return NULL;
        }

        info->func = func;
        info->data = data;
        info->prio_level = prio_level;
        #if NEW_GLIB_THREAD_API
        thread = g_thread_try_new (name, fluid_thread_high_prio, info, &err);
        #else
        thread = g_thread_create (fluid_thread_high_prio, info, detach == FALSE, &err);
        #endif
        }
        #if NEW_GLIB_THREAD_API
        else thread = g_thread_try_new (name, (GThreadFunc)func, data, &err);
        #else
        else thread = g_thread_create ((GThreadFunc)func, data, detach == FALSE, &err);
        #endif

        if (!thread)
        {
        FLUID_LOG(FLUID_ERR, "Failed to create the thread: %s",
        fluid_gerror_message (err));
        g_clear_error (&err);
        return NULL;
        }

        #if NEW_GLIB_THREAD_API
        if (detach) g_thread_unref (thread);  // Release thread reference, if caller wants to detach
        #endif

        return thread;*/
        return 0;
    }

    /**
    * Frees data associated with a thread (does not actually stop thread).
    * @param thread Thread to free
    */
    void
        delete_fluid_thread(void* thread)
    {
        // TODO FIX ME

        /* Threads free themselves when they quit, nothing to do */

        delete reinterpret_cast<std::thread*>(thread);
    }
}
