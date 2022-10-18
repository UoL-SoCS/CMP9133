#include <thread>
#include <iostream>
#include <time.h>
#include <Multiplier.h>
#include <ThreadPool.h>

#define NUM_MATRIX_MULT 10

using namespace std;

class ThreadedMultiplier {
	int numthreads;
public:
	ThreadedMultiplier(const char*);
	void run();
};

ThreadedMultiplier::ThreadedMultiplier(const char* _numthreads) {
	int numthreads = atoi(_numthreads);
	int numcores = std::thread::hardware_concurrency();
	cout << "numcores=" << numcores << endl;

	int maxnumthreads = numcores * 2;
	if (numthreads <= maxnumthreads) {
		this->numthreads = numthreads;
	} else {
		this->numthreads = maxnumthreads;
	}
}

void ThreadedMultiplier::run() {
	ThreadPool threads(this->numthreads);
	for (int i=1; i<=NUM_MATRIX_MULT; i++) {
		threads.enqueue([i] {
			Multiplier multiplier = Multiplier();
			multiplier.run();
			cout << "Matrix multiplication " << i << endl;
		});
		//cout << "res=" << res << endl;
	}
}

int main(int argc, const char* argv[]) {
	clock_t starttime, endtime;
	starttime = clock();

	if (argc != 2) {
		cout << "Usage: " << argv[0] << " NUM_THREADS" << endl;
	} else {
		(new ThreadedMultiplier(argv[1]))->run();
	}

	endtime = clock();
	double exectime = (double)(endtime - starttime) / CLOCKS_PER_SEC;
	cout << "ExecutionTime=" << exectime << "secs." << endl;

	return 0;
}