/* thrdcst.h -- declares functions for CST threadsafety 
 *
 * These functions are used only in lockprng.c and lockut.c, but can be
 * used more widely if necessary.
 */

#ifndef _THRDCST_H
#define _THRDCST_H

#ifdef __cplusplus
extern "C" {
#endif

/* Errors */
#define THREAD_EBASE (0x0d000000) /* Module Code */
#define THREAD_ENOSEM (THREAD_EBASE + 0x00000) /* out of semaphors */
#define THREAD_ENOSEMG (THREAD_EBASE + 0x00001) /* failed semaphore get */
#define THREAD_ENOSEML (THREAD_EBASE + 0x00002) /* failed semaphore lock */
#define THREAD_ENOSEMU (THREAD_EBASE + 0x00003) /* failed semaphore unlock */
#define THREAD_ENOSEMS (THREAD_EBASE + 0x00004) /* failed semaphore set */
#define THREAD_ENOSEMI (THREAD_EBASE + 0x00005) /* failed semaphore init */

#define THREAD_ENOMXMEM (THREAD_EBASE + 0x00006) /* out of mutex memory */

typedef void *(*CST_AllocFunction) (size_t);
typedef void (*CST_FreeFunction) (void *);
typedef void (*CST_ExitFunction) (void *);

struct ut_threadops_s {
  /* Mutexes */
  void *(*Mutex_new) (CST_AllocFunction f_alloc, CST_FreeFunction f_free);
  int (*Mutex_lock) (void *mutex);
  int (*Mutex_unlock) (void *mutex);
  void (*Mutex_kill) (void *mutex, CST_FreeFunction f_free);

  /* Thread-local storage */
  void *(*Storage_new) (CST_ExitFunction f_kill, CST_AllocFunction f_alloc, CST_FreeFunction f_free);
  int (*Storage_put) (void *storage, void *data);
  void *(*Storage_get) (void *storage);
  void (*Storage_kill) (void *storage, CST_FreeFunction f_free);

#ifdef WITH_rwmutex
  /* RW Mutexes */
  void *(*RWMutex_new) (CST_AllocFunction f_alloc, CST_FreeFunction f_free);
  int (*RWMutex_readLock) (void *mutex);
  int (*RWMutex_writeLock) (void *mutex);
  int (*RWMutex_unlock) (void *mutex);
  void (*RWMutex_kill) (void *mutex, CST_FreeFunction f_free);
#endif /* WITH_rwmutex */
};

/* All operations return 0 on success, -1 on failure */

typedef struct cst_mutex_s CSTMutex;

struct cst_mutex_s {
  int (*Lock)(CSTMutex *);
  int (*Unlock)(CSTMutex *);
  void (*Destroy)(CSTMutex *);
  int init; /* Is it an init mutex or a standard mutex */
  void *state;
};

/* start up a mutex structure for a specific block of code. Returns 0 on
 * failure (out of memory). If we're not running in multithreaded mode
 * returns a dummy mutex.
 */

CSTMutex *new_CSTMutex(void);

/* The CSTMutex type used in ut_init(), ut_shutdown(). */
 
CSTMutex *new_CSTInitMutex(void);

#ifdef __cplusplus
}
#endif

#endif  /* ndef _THRDCST_H */
