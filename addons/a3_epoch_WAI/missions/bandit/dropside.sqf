/*
All the code and information provided here is provided under a Commons License.
http://creativecommons.org/licenses/by-sa/3.0/
*/
if(isServer) then {
	private			["_rndnum","_complete","_dir","_crate_type","_mission","_position","_vehclass3","_vehclass2","_vehicle3","_vehicle2","_playerPresent","_vehicle","_vehclass","_crate"];

	// Get mission number, important we do this early
	_mission 		= count wai_mission_data -1;
	waitUntil{!isNil "_mission"};

	// position roads
	_fn_position	= [5,0] call find_position;
	_position		= _fn_position select 0;
	_missionType	= _fn_position select 0;
	
	[_mission,_position,"hard","Dropside Truck Crash","MainBandit",true] call mission_init;
	diag_log 		format["WAI: [Mission:Ikea Truck]: Starting... %1",_position];

	//Setup the crate
	_crate = [2,_position] call wai_spawn_create;
	//Base
	_baserunover 	= createVehicle ["Land_Wreck_Truck_dropside_F",[((_position select 0) + 7), ((_position select 1) + 7),0],[],10,"CAN_COLLIDE"];
	_burn   = "test_EmptyObjectForFireBig" createVehicle (position _baserunover); 
	_burn  attachto [_baserunover, [0,0,-1]];
	_baserunover 	setVectorUp surfaceNormal position _baserunover;
	
	//Troops
	_rndnum 	= 3 + round (random 2);
	[[(_position select 0) + (random(10)+1),(_position select 1) - (random(15)+1),0],_rndnum,"hard",[1,"AT"],"bandit",_mission] call spawn_group;
	[[(_position select 0) + (random(10)+1),(_position select 1) - (random(15)+1),0],_rndnum,"hard",0,"bandit",_mission] call spawn_group;
	[[(_position select 0) + (random(10)+1),(_position select 1) - (random(15)+1),0],_rndnum,"Hard",0,"bandit",_mission] call spawn_group;
	//[[(_position select 0) + (random(10)+1),(_position select 1) - (random(15)+1),0],_rndnum,"Hard",0,"bandit",_mission] call spawn_group;

	//Static Guns
	[
		[
			[(_position select 0) + 25, (_position select 1) + 25, 0],
			[(_position select 0) - 25, (_position select 1) - 25, 0]
		],
		"O_HMG_01_high_F",
		"hard","bandit",
		_mission
	] call spawn_static;

		
	// Spawn Vehicles
	/*_dir 			= floor(round(random 360));

	_vehclass 		= cargo_trucks 		call BIS_fnc_selectRandom;		// Cargo Truck
	_vehclass2 		= refuel_trucks 	call BIS_fnc_selectRandom;		// Refuel Truck
	_vehclass3 		= military_unarmed 	call BIS_fnc_selectRandom;		// Military Unarmed

	//_vehicle		= [_vehclass,_position,_mission,false,_dir] call custom_publish;
	//_vehicle2		= [_vehclass2,_position,_mission,false,_dir] call custom_publish;
	//_vehicle3		= [_vehclass3,_position,_mission,false,_dir] call custom_publish;
	
	if(debug_mode) then {
		diag_log format["WAI: [Bandit] ikea_convoy spawned a %1",_vehclass];
		diag_log format["WAI: [Bandit] ikea_convoy spawned a %1",_vehclass3];
		diag_log format["WAI: [Bandit] ikea_convoy spawned a %1",_vehclass2];
	};
	*/
	
	//Condition
	_complete = [
		[_mission,_crate],				// mission number and crate
		["crate"], 						// ["crate"], or ["kill"], or ["assassinate", _unitGroup],
		[_baserunover],	// cleanup objects
		"A Renegade Dropside Truck has crashed, They are securing the parameter. See if you can make the building supplies yours.",	// mission announcement
		"Survivers have successfully ambushed the crash site and secured the building supplies!",			// mission success
		"Survivers were unable to secure the building supplies"									// mission fail
	] call mission_winorfail;

	if(_complete) then {
		[_crate,[1,crate_weapons_buildables],[4,crate_tools_buildable],[30,crate_items_buildables],4] call dynamic_crate;
	};

	diag_log format["WAI: [Mission: Dropside Truck Crash]: Ended at %1",_position];
	
	b_missionsrunning = b_missionsrunning - 1;
};