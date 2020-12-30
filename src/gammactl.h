#ifndef GAMMACTL_H
#define GAMMACTL_H

#include <vector>
#include <thread>
#include "defs.h"
#include "component.h"
#include "mediator.h"
#include "screenctl.h"

class GammaCtl : public DspCtl, public Component
{
public:
	GammaCtl();

	void start();
	void stop();

	void notify_ss();
	void notify_temp(bool force = false);
private:
	void captureScreen();
	int  calcBrightness(const std::vector<uint8_t> &buf, int bpp = 4, int skip_mult = 1);
	void adjustBrightness(convar &br_cv);
	void adjustTemperature();
	void reapplyGamma();
	void notify_all_threads();

	std::vector<std::thread> threads;
	convar ss_cv;
	convar temp_cv;
	convar reapply_cv;
	std::mutex brt_mtx;
	int brt_step;
	int temp_step;
	int ss_brightness = 0;
	bool br_needs_change   = false;
	bool force_temp_change = false;
	bool quit              = false;
};

#endif // GAMMACTL_H