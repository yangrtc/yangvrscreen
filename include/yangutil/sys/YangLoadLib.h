/*
 * YangLoadSo.h
 *
 *  Created on: 2020-09-20
 *      Author: yang
 */

#ifndef YANGUTIL_SYS_YANGLOADLIB_H_
#define YANGUTIL_SYS_YANGLOADLIB_H_

#ifdef __WIN32__
#include <minwindef.h>
#endif
class YangLoadLib{
public:
	YangLoadLib();
	~YangLoadLib();

void *loadObject(const char *sofile);
void *loadSysObject(const char *sofile);
void *loadFunction(const char *name);
void unloadObject();

#ifdef __WIN32__
HMODULE m_handle;
char *dlerror();
#else
void *m_handle;
#endif

};

#endif /* YANGUTIL_SYS_YANGLOADLIB_H_ */
