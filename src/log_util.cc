/*
 * log_util.cc
 *
 *  Created on: Mar 22, 2014
 *      Author: chncwang
 */

#include "log_util.h"

#include <memory>

#include <log4cplus/logger.h>
#include <log4cplus/configurator.h>
#include <log4cplus/layout.h>
#include <log4cplus/consoleappender.h>
#include <log4cplus/helpers/pointer.h>

using namespace log4cplus;
using std::auto_ptr;

namespace fool2048 {

void InitLogConfig() {
  initialize();
  PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT("log4cplus.properties"));
}

}
