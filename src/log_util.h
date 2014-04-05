/*
 * log_util.h
 *
 *  Created on: Mar 22, 2014
 *      Author: chncwang
 */

#ifndef LOG_UTIL_H_
#define LOG_UTIL_H_

#include "log4cplus/logger.h"
#include "log4cplus/loggingmacros.h"

void InitLogConfig();

#define LOG_UTIL_DEBUG(expression) \
  LOG4CPLUS_DEBUG(log4cplus::Logger::getRoot(), LOG4CPLUS_TEXT(expression))

#endif /* LOG_UTIL_H_ */
