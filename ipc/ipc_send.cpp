#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>


int main(int argc, char *argv[])
{
   using namespace boost::interprocess;

	//Remove shared memory on construction and destruction
	struct shm_remove
	{
	 shm_remove() { shared_memory_object::remove("MySharedMemory"); }
	 ~shm_remove(){ shared_memory_object::remove("MySharedMemory"); }
	} remover;

	//Create a shared memory object.
	shared_memory_object shm (create_only, "MySharedMemory", read_write);

	//Set size
	shm.truncate(100000);

	//Map the whole shared memory in this process
	mapped_region region(shm, read_write);

	//Write all the memory to 1
	std::memset(region.get_address(), 2, region.get_size());

	std::cout << "ipc send complete" << std::endl;

 	using namespace std::chrono_literals;
 	std::this_thread::sleep_for(10s);

  return 0;
}
