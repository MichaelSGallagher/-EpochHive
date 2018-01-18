class CfgPatches {
	class epoch_SPKcode_config {
		requiredAddons[] = {"A3_epoch_server"};
		fileName = "epoch_SPKcode_config.pbo";
		requiredVersion = 1.66;
		author[]= {"Sp4rkY"};
	};
};
#include "toggle.h"
class CfgFunctions {
	class SPKcode_server_config {
		tag="SPK";
		class SPK_addons {
			file = "x\addons\epoch_SPKcode_config";
			class config {postInit=1;};
		};
	};
};
