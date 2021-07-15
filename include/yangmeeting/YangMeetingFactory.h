/*
 * YangUtilFactory.h
 *
 *  Created on: 2020年10月17日
 *      Author: yang
 */

#ifndef YANGVIDEOMEETING_INCLUDE_YANGUTILFACTORY_H_
#define YANGVIDEOMEETING_INCLUDE_YANGUTILFACTORY_H_
#include <yangmeeting/yangmeetingtype.h>
#include "YangMeetingHandle.h"
#include "yangutil/sys/YangSysMessageHandle.h"
class YangMeetingFactory{
public:
	YangMeetingFactory();
	void createIni(const char* p_filename,YangMeetingContext *pini);
	YangMeetingHandle* createMeetingHandle(YangMeetingContext *pini);
	YangMeetingHandle* getMeetingHandle(YangSysMessageHandle *phandle);
	YangSysMessageHandle* createSysMessageHandle(YangMeetingContext *pini,YangReceiveMessageI* prec);
};




#endif /* YANGVIDEOMEETING_INCLUDE_YANGUTILFACTORY_H_ */
