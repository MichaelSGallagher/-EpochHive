serverRestart         = "false"; // true sends #shutdown command to server after the time specified in ForceRestartTime
forceRestartTime      = 14400; // 4 hour restarts

StorageSlotsLimit = 1500; // Max storage slots allowed. Warning! Higher the number lower performance.
BuildingSlotsLimit = 1500; // Max building slots allowed. Warning! Higher the number lower performance.

// Time based
StaticDateTime[] = {0,0,0,14,0}; //  would forces the server to start at 8am each time it is started while allowing the year, month and day to stay real time. Any values left at 0 will result in no change.
timeDifference = 0; // Server uses real time this will allow you to offset just the hour.
timeMultiplier = 4; // Sets a time multiplier for in-game time. The command range is now capped at 0.1 - 120 to avoid performance problems.
lootMultiplier = 1; // 1 = max loot bias. This controls how much loot can payout per Epoch loot container.
// Events
WeatherStaticForecast[] = {75.5,0,{0,0,0},0,{1,1}}; // Default: {75.5,0,{0,0,0},0,{1,1}}; // Clear day; {19,1,{1,1,40},1,{5,5}}; // Cold Foggy Rainy Overcast Windy; Format: {temp <scalar>,rain <scalar>,fog <array>,overcast <scalar>,wind <array>}
events[] = {
    { 3600, "CarnivalSpawner", 0 , 1, -1, {} ,{"VR"}}, // SECOND <scalar>, EVENT <string>, INIT <scalar> 1 = run script at startup or 0 normal delay, PREPOSTFIX <scalar> 1 = use pre/postfix path (inside epoch settings pbo) 0 = use full file path, RUNNUMTIMES <scalar> -1 infinite, execVM payload <array>, disallowed worlds <array>
    // { 1800, "PaydayEvent", 0, 1},
    // { 1200, "MessageServer", 0, 1},
    { 2700, "AirDrop", 0 , 1, -1, {} ,{"VR"}},
    { 2400, "EarthQuake", 0 , 1, -1, {} ,{"VR"}},
	{ 2700, "Satellite", 0 , 1, -1, {} ,{"VR"}},
    { 900, "ChangeWeather", 1 , 1, -1, {} ,{"VR"}},
    { 1200, "ContainerSpawner", 0 , 1, -1, {} ,{"VR"}},
	{ 1440, "GardenManager", 0 , 1, -1, {} ,{"VR"}},
    { 300, "PlantSpawner", 0 , 1 , -1, {} ,{"VR"}} //No comma on last Entry
};

// Antagonists
antagonistChancePDeath = 0.33; //33% chance when player was killed from a other player (selfkill doesn't count)

// Player Related
cloneCost = 100; 					// debt incurred on player death
MaxBankDebitforTrade = -50000;		// If Player has less money on Bank, Crypto from Trade goes directly to Bank instead to Player

// Default Loadout
defaultUniformFemale =		"U_O_FullGhillie_lsh";
defaultVestFemale =			"V_F35_EPOCH";
defaultUniformMale =		"U_O_FullGhillie_lsh";
defaultVestMale =			"V_35_EPOCH";
defaultGoggles =			"G_Tactical_Black";
defaultHeadgear =			"H_40_EPOCH";
defaultBackpack =			"B_Carryall_oucamo";
defaultprimaryWeapon[] =	{"arifle_SPAR_03_blk_MOS_Pointer_Bipod_F","","acc_pointer_IR","",{"20Rnd_762x51_Mag",20},{},""};
defaultsecondaryWeapon[] = 	{};
defaulthandgunWeapon[] =	{"hgun_Pistol_heavy_01_snds_F","","","",{"11Rnd_45ACP_Mag",11},{},""};
defaultuniformItems[] =		{{"FAK",1},{"20Rnd_762x51_Mag",2,30},{"Chemlight_green",1,1}};
defaultvestItems[] =		{{"20Rnd_762x51_Mag",3,30},{"11Rnd_45ACP_Mag",2,11},{"SmokeShell",1,1}};
defaultbackpackItems[] =	{{"FAK",1},{{"hgun_Pistol_heavy_01_snds_F","","","",{"11Rnd_45ACP_Mag",11},{},""},1}};
defaultassignedItems[] =	{"Rangefinder","","","",{},{},""};
defaultlinkedItems[] =		{
	"ItemMap", // "ItemMap"
	"ItemGPS", // "ItemGPS" or "ItemGeigerCounter_EPOCH",
	"EpochRadio0", // "EpochRadio0" through "EpochRadio9"
	"ItemCompass", // "ItemCompass"
	"ItemWatch", // "ItemWatch"
	"NVG_EPOCH"  // "NVG_EPOCH" or "radiation_mask_epoch"
};

// vehicles - Max vehicle slots is calculated from per vehicle limits below. Warning! Higher the number lower the performance.
disableAutoRefuel = "false"; // Removes auto refuel from all buildings at server startup.
simulationHandlerOld = "false"; // When enabled this feature disables simulation on vehicles that are not nea players. Can help improve client fps at the cost of server fps.
vehicleLockTime = 1800; // Controls how many seconds it takes to allow another person/group to unlock vehicle.
VehLockMessages = "true";		// Give players a hint, that the Vehicle is locked / unlocked
removevehweapons[] = {};			// remove these Weapons from spawned Vehicles
	

removevehmagazinesturret[] = {};	// Remove these Magazines from the given Turret from spawned Vehicles
	

disableVehicleTIE = "false";

// BaseBuilding
UseIndestructible = "true";			// Enable / Disable Indestructible BaseObjects
IndestructibleBaseObjects[] =	{	// Can be Names or Classes
									"Constructions_static_F",
									"Buildable_Storage",
									"PlotPole_EPOCH",
									"LockBox_EPOCH",
									"Safe_EPOCH"
								};
ExceptedBaseObjects[] = 		{	// Not Indestructible, also if in a Class of IndestructibleBaseObjects
									"CinderWallGarage_EPOCH",
									"WoodLargeWallDoorL_EPOCH",
									"WoodLargeWallDoor_EPOCH",
									"WoodWall4_EPOCH"
								};

// Traders
taxRate = 0.0; // controls the price increase for purchases
starterTraderItems[] = {{"WhiskeyNoodle","ItemCoolerE","Hatchet","16Rnd_9x21_Mag","PaintCanGrn","HeatPack","ItemGoldBar10oz","Chemlight_green","HandGrenade","30Rnd_9x21_Mag","6Rnd_45ACP_Cylinder","20Rnd_556x45_UW_mag","5Rnd_rollins_mag","9rnd_45X88_magazine","ItemScraps","optic_Holosight_smg","30Rnd_65x39_caseless_green","SmokeShellRed","SmokeShellBlue","20Rnd_762x51_Mag","emptyjar_epoch","muzzle_snds_H","SmokeShellOrange","5Rnd_127x108_APDS_Mag","arifle_Mk20C_plain_F","ChainSaw","30Rnd_65x39_caseless_mag_Tracer","30Rnd_65x39_caseless_mag","muzzle_snds_M","muzzle_snds_B","C_Van_01_box_EPOCH","honey_epoch","ItemEmerald","30Rnd_556x45_Stanag","30Rnd_762x39_Mag","PaintCanOra","11Rnd_45ACP_Mag","MortarBucket","FoodSnooter","PaintCanBlk","PaintCanBlu","PaintCanYel","optic_Holosight","arifle_MX_F","200Rnd_65x39_cased_Box","LMG_Mk200_F","Binocular","arifle_Mk20_plain_F","H_14_EPOCH","optic_Aco_smg","7Rnd_408_Mag","200Rnd_556x45_M249","9Rnd_45ACP_Mag","30Rnd_45ACP_Mag_SMG_01","V_4_EPOCH","V_16_EPOCH","hgun_PDW2000_F","jerrycan_epoch","100Rnd_65x39_caseless_mag","hgun_P07_F","SmokeShellGreen","Pelt_EPOCH","NVG_EPOCH","MiniGrenade","CircuitParts","optic_Yorris","10Rnd_762x51_Mag","5Rnd_127x108_Mag","6Rnd_GreenSignal_F","hgun_Pistol_Signal_F","SmokeShell","optic_Aco","hgun_Pistol_heavy_01_F","arifle_MXC_F","hgun_Rook40_F","M14Grn_EPOCH","SmokeShellPurple","muzzle_snds_H_MG","acc_flashlight","m249Tan_EPOCH","SMG_02_F","m249_EPOCH","200Rnd_65x39_cased_Box_Tracer","30Rnd_556x45_Stanag_Tracer_Yellow","optic_DMS","Towelette","acc_pointer_IR"},{ 1,4,0,11,1,2,2,19,16,5,5,2,2,2,1,1,2,1,2,1,0,1,15,0,1,0,2,0,2,2,0,0,1,8,2,1,11,0,0,0,1,1,1,3,13,1,2,1,0,2,2,2,9,4,1,1,2,0,1,1,14,1,0,8,0,1,1,0,2,1,14,3,1,1,1,0,14,1,1,1,1,1,1,1,1,2,1}}; // Starter Items for fresh spawned trader first array is classnames second is quantity.
NPCSlotsLimit = 30; // Max number of traders static or dynamic. Warning! Higher the number lower performance.
forceStaticTraders = "true"; // disables traders moving from work to home

forcedVehicleSpawnTable = ""; // leave blank for default. Options: "allowedVehiclesList","allowedVehiclesList_CUP","allowedVehiclesList_MAD","allowedVehiclesList_MADCUP"
forcedLootSpawnTable = ""; // leave blank for default. Options: "CfgLootTable","CfgLootTable_CUP","CfgLootTable_MAD","CfgLootTable_MADCUP"

// Markers
showEarthQuakes = "true"; // show mineral viens caused by earthquakes
showSatellites = "true"; // show crashed Satellites
showShippingContainers = "true"; // Show location of events based loots (plants, shipping container, Carnival)
SHOW_TRADERS = "true"; // Show locations of traders
SHOW_JAMMERS = "true"; // Shows location of base jammers
SHOW_BOATLOOT = "true"; // Shows the location of shipwreck loot
DEBUG_VEH = "false"; // DEBUG ONLY used to debug spawing of vehicles

// Hive Related
expiresBuilding = "604800";  // expiration date in seconds for buildings
expiresPlayer = "2592000";  // expiration date in seconds for players
expiresBank = "7776000";  // expiration date in seconds for players bank
expiresVehicle = "604800";  // expiration date in seconds for vehicles
expiresAIdata = "604800";  // expiration date in seconds for NPC Trader inventory
expiresCommunityStats = "7776000"; // expiration date in seconds for players community stats

// Admin Features
hiveAdminCmdExec = "false"; // true = enables extra (To Be Released) feature to allow execution of code via hive.
hiveAdminSavePlayerList = "true"; // true = enables saving of playerUID array to hive value PLAYERS:#InstanceID.
hiveAdminCmdTime = 5; // how many seconds between each command queue call.

// DEBUG
useOldLoadVehicles = "false";
enableUnitTestOnStart = 1; // enable extra debug for database calls. 1 = enabled.
