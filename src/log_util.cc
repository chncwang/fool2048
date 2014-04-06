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
using namespace log4cplus::helpers;
using std::auto_ptr;

void InitLogConfig() {
  initialize();
  BasicConfigurator config;
  config.configure();
  SharedObjectPtr<Appender> appender(new ConsoleAppender());
  tstring pattern =
      LOG4CPLUS_TEXT("%D{%H:%M:%S,%Q} - %M%n");
  appender->setLayout(auto_ptr<Layout>(new PatternLayout(pattern)));
  Logger::getRoot().addAppender(appender);
}
