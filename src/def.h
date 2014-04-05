/*
 * def.h
 *
 *  Created on: Mar 21, 2014
 *      Author: chncwang
 */

#ifndef DEF_H_
#define DEF_H_


#define DISALLOW_COPY_AND_ASSIGN(class_name) \
    class_name(const class_name &) = delete; \
    class_name &operator =(const class_name &) = delete


#endif /* DEF_H_ */
