[] spawn {
	_addons = configFile >> "CfgSPKcode_config" >> "Addons";
	if(getText(_addons >> "_ESVP") isEqualTo str(true))then{[] spawn SPK_fnc_initESVP_server};

	diag_log "(SPK-DEBUG): SPKcode configfile loaded";
};
