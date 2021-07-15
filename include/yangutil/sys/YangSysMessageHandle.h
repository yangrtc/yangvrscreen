#ifndef INCLUDE_YANGUTIL_SYS_YANGSYSMESSAGEHANDLE_H_
#define INCLUDE_YANGUTIL_SYS_YANGSYSMESSAGEHANDLE_H_
#include "yangutil/sys/YangSysMessageI.h"
#include <vector>
#include <mutex>
#include "yangutil/sys/YangThread.h"
using namespace std;

class YangSysMessageHandle :public YangThread{
public:
	YangSysMessageHandle();
	virtual ~YangSysMessageHandle();
	virtual void handleMessage(YangSysMessage* mss)=0;
	virtual void initAll()=0;
	virtual void deleteAll()=0;
	void putMessage(YangSysMessageI *handle,int pst, int puid, int handleState, int optType);
	static YangSysMessageHandle* m_instance;
	int m_isStart;
    int m_loop;
    void stop();
protected:
   void run();
   void startLoop();
   void stopLoop();
private:

   vector<YangSysMessage*> m_sysMessages;
   mutex m_lock;
};

#endif /* INCLUDE_YANGUTIL_SYS_YANGSYSMESSAGEHANDLE_H_ */
