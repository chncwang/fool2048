/*
 * log_util.h
 *
 *  Created on: Mar 22, 2014
 *      Author: chncwang
 */

#ifndef SRC_LOG_UTIL_H_
#define SRC_LOG_UTIL_H_

#include "log4cplus/logger.h"
#include "log4cplus/loggingmacros.h"

namespace fool2048 {

void InitLogConfig();

#define LOG_UTIL_DEBUG(expression) \
  LOG4CPLUS_DEBUG(log4cplus::Logger::getRoot(), LOG4CPLUS_TEXT(expression))
#define LOG_UTIL_ERROR(expression) \
  LOG4CPLUS_ERROR(log4cplus::Logger::getRoot(), LOG4CPLUS_TEXT(expression))

}

#endif /* SRC_LOG_UTIL_H_ */
