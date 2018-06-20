#include <iostream>
#include "glog/logging.h"
#include "glog/raw_logging.h"

#define ADEBUG VLOG(4) << "[DEBUG] "
#define AINFO LOG(INFO)
#define AWARN LOG(WARNING)
#define AERROR LOG(ERROR)
#define AFATAL LOG(FATAL)

int main(int argc, char** argv) {
	google::SetLogDestination(google::GLOG_INFO,"/home/yimeng/cpp_examples/log.txt" );
    google::InitGoogleLogging(argv[0]);        
	AINFO << "hello";
	return 0;
}