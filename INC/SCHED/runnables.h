#ifndef RUNNABLES_H_
#define RUNNABLES_H_

/*****************************************************************************/
/*                              Includes                                     */
/*****************************************************************************/
#include <stdint.h>

/*****************************************************************************/
/*                              Defines                                      */
/*****************************************************************************/
#define SCHED_TIME_MS       5

/*****************************************************************************/
/*                              Types                                        */
/*****************************************************************************/
typedef enum {
    Hsw_runnable,
    App_runnable,
    _runsNum
}runnables_t;


/*****************************************************************************/
/*                          Function Prototypes                              */
/*****************************************************************************/

#endif /* RUNNABLES_H_ */