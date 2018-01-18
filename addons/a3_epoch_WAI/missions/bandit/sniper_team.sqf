if(isServer) then {

	private 		["_rndnum","_unitGroup","_complete","_vehicle","_rndnum","_crate_type","_crate","_mission","_tanktraps","_mines","_playerPresent","_cleanmission","_currenttime","_starttime","_missiontimeout","_vehname","_veh","_position","_vehclass","_vehdir","_objPosition"];

	// Get mission number, important we do this early
	_mission 		= count wai_mission_data -1;
	waitUntil{!isNil "_mission"};
	
	_fn_position	= [5] call find_position;
	_position		= _fn_position select 0;
	_missionType	= _fn_position select 2;
	
	[_mission,_position,"easy","Sniper Team","MainBandit",true] call mission_init;

	diag_log 		format["WAI: [Mission: Sniper Team]: Starting... %1",_position];

	_crate = [0,_position] call wai_spawn_create;
	
	// Base
	_baserunover 	= createVehicle ["Land_HelipadEmpty_F",[((_position select 0) + 5), ((_position select 1) + 5), -150],[],10,"CAN_COLLIDE"];
	_baserunover 	setVectorUp surfaceNormal position _baserunover;
	
	// Unit
	_rndnum 	= 3 + round (random 6);
	_unitGroup = [[(_position select 0) + (random(30)+1),(_position select 1) - (random(35)+1),0],_rndnum,"easy","random","bandit",_mission] call spawn_group;
		
	// Condition
	_complete = [
		[_mission,_crate],			// mission number and crate
		["crate"], // ["crate"], or ["kill",wai_kill_percent], or ["assassinate", _unitGroup],
		[_baserunover], 			// cleanup objects
		"Our scouts have spotted a sniper team, check the map for their location",	// mission announcement
		"Survivers have killed the snipers!",											// mission success
		"Survivers did not secure the sniper rifles in time"							// mission fail
	] call mission_winorfail;
	
	if(_complete) then {
		[_crate,[8,ai_sniper_wep],[10,(ai_sniper_gear+ai_sniper_skin+ai_sniper_scope)],0,0] call dynamic_crate;
	};

	diag_log format["WAI: [Mission: Sniper Team]: Ended at %1",_position];
	
	b_missionsrunning = b_missionsrunning - 1;
};