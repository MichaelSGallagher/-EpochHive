/*
	Author: Aaron Clark - EpochMod.com

    Contributors:

	Description:
	Epoch gamemode server Side map specific configs for australia.

    Licence:
    Arma Public License Share Alike (APL-SA) - https://www.bistudio.com/community/licenses/arma-public-license-share-alike

    Github:
    https://github.com/EpochModTeam/Epoch/tree/release/Sources/epoch_server_settngs/configs/maps/australia.h
*/
class Australia : Default
{
	worldSize = 55000;
	plantLimit = 20;
	vehicleSpawnTypes[] = {
		{"FlatAreaCity",1},
		{"FlatAreaCitySmall",1},
		{"NameCity",2},
		{"NameVillage",1},
		{"NameCityCapital",4},
		{"Airport",5},
		{"NameLocal",2},
		{"StrongpointArea",1},
		{"VegetationBroadleaf",1},
		{"VegetationFir",1},
		{"ViewPoint",1}
	};
	traderBlds[] = { "Land_A_FuelStation_Build", "Land_A_GeneralStore_01", "Land_A_GeneralStore_01a", "Land_A_Office01", "Land_Ind_Garage01", "Land_Ind_Workshop01_04", "Land_Ind_Workshop01_L", "Land_Shed_Ind02", "Land_Tovarna2", "Land_sara_hasic_zbroj" };
	telePos[] = {
		// N [-0.286865,8.17383,-10.3098]
		// S [-0.415527,-7.05298,-10.3098]
		// E [13.5127,0.410156,-10.3098]
		// W [-14.4316,0.112793,-10.3098]
			{ "Transport_C_EPOCH", { -0.415527, -7.05298, -10.3098 }, "", { 24398.3, 13971.6, 0 } }, // Central
			{ "Transport_E_EPOCH", { 13.5127, 0.410156, -10.3098 }, "", { 34751.5, 13431.9, 0 } }, // East
			{ "Transport_N_EPOCH", { -0.286865, 8.17383, -10.3098 }, "", { 19032.7, 33974.6, 0 } }, // North
			{ "Transport_W_EPOCH", { -14.4316, 0.112793, -10.3098 }, "", { 4056.35, 19435.9, 0 } }  // West
	};
	propsPos[] = {
    // North camp
    {"Land_Slums02_4m", {19040.4, 33976.5, 0}, 271.364},
    {"Land_Slums02_4m", {19040.4, 33972.6, 0}, 271.364},
    {"Land_Slums02_4m", {19040.4, 33968.7, 0}, 271.364},
    {"Land_Slums02_4m", {19040.5, 33964.7, 0}, 268.182},
    {"Land_Slums02_4m", {19040.7, 33961.2, 0}, 263.182},
    {"Land_Slums02_4m", {19041, 33957.4, 0}, 273.182},
    {"Land_Slums02_4m", {19038.8, 33978.5, 0}, 195.909},
    {"brownrock2", {19026.3, 33985.3, 0}, 25.4545},
    {"Land_MarketShelter_F", {19037.4, 33967, 0.391932}, 269.545},
    {"Land_Slums02_4m", {19039.4, 33955.8, 0}, 1.81819},
    {"Land_Slums02_4m", {19035.5, 33955.9, 0}, 1.81821},
    {"Land_Slums02_4m", {19031.6, 33955.9, 0}, 1.81821},
    {"Land_Slums02_4m", {19026.2, 33957.5, 0}, 94.0909},
    {"Land_Slums02_4m", {19026.4, 33961.4, 0}, 94.0909},
    {"Land_BarGate_F", {19026.1, 33968, -0.0194139}, 267.727, false},
    {"Land_Slums02_4m", {19027.6, 33956, 0}, 1.81821},
    {"Campfire_burning_F", {19037.5, 33971.2, 0}, 0},
    {"Land_WoodPile_large_F", {19028.4, 33961.1, 0}, 0},
    {"Land_Pallets_F", {19029.6, 33957.5, 0}, 49.0909},
    {"Land_Pallet_vertical_F", {19027.4, 33958.2, 0}, 0},
    {"Land_Bricks_V2_F", {19027.4, 33957.6, 0}, 0},
    {"Land_WoodenBox_F", {19037.8, 33976.7, 0}, 0},
    {"Land_WoodenBox_F", {19038.1, 33975, 0}, 326.364},
    {"Land_WoodenBox_F", {19037.7, 33975.7, 0.445431}, 85.909},
    {"Land_WorkStand_F", {19032.6, 33958.6, 0}, 321.364},
    {"Land_Axe_fire_F", {19032.1, 33958, 0.843244}, 35.4546},
    {"Land_Coil_F", {19037.9, 33959.7, 0}, 0},
    {"Land_CrabCages_F", {19029.6, 33973.2, 0}, 0},
    {"Land_GarbageBarrel_01_F", {19025.9, 33972.8, 0}, 341.364},
    {"Land_Tyres_F", {19037.7, 33963.4, 0}, 0},
    {"Land_Cargo40_grey_F", {19048.2, 33970, 2.5386}, 62.2727},
    {"Land_Cargo40_red_F", {19048.3, 33964.6, -0.107983}, 14.5454},
    {"CargoNet_01_barrels_F", {19039.4, 33967.6, 0}, 0},
    {"MetalBarrel_burning_F", {19025.3, 33963.5, 0}, 31.3636},
    {"Land_Cargo20_military_green_F", {19045.3, 33975.6, 0}, 0},
    // East camp
    {"Land_Wreck_Truck_F", {34764, 13428.5, 0}, 0},

    {"Land_cargo_house_slum_F", {34761.5, 13431.2, 0.00321865}, 146.443},

    {"Land_cargo_addon01_V2_F", {34746, 13425.2, 0}, 117.155},


    {"Campfire_burning_F", {34756, 13434.6, 0}, 0},

    {"Land_WoodPile_F", {34760.7, 13434.1, 0}, 53.4089},

    {"Land_bags_EP1", {34746.7, 13428.7, 0}, 0},

    {"Land_bags_stack_EP1", {34748.2, 13430.7, 0}, 0},

    {"JeepWreck1", {34743.9, 13427, 0}, 0},

    {"Paleta2", {34760.7, 13427.8, 0}, 0},

    {"Land_Barrel_sand", {34761.8, 13429.2, 0}, 0},

    {"Land_Wheel_cart_EP1", {34761.4, 13425.3, 0}, 0},

    {"Land_HBarrier_5_F", {34759.2, 13438.6, 0}, 0},

    {"Land_HBarrier_5_F", {34764.7, 13437, -0.00175285}, 42.6258},

    {"Land_HBarrier_5_F", {34753.7, 13437.6, 0}, 161.949},

    {"Land_HBarrier_5_F", {34748.6, 13434.9, 0}, 141.275},

    {"Land_HBarrier_5_F", {34744.1, 13431.4, 0}, 139.552},

    {"Land_HBarrier_5_F", {34741.7, 13426.2, 0}, 91.3118},

    {"Land_HBarrier_5_F", {34768, 13432.3, -0.00434589}, 68.9146},

    {"Land_HBarrier_5_F", {34767.6, 13426.7, -0.00529385}, 117.155},

    {"Land_HBarrier_5_F", {34763.5, 13422.7, 0}, 153.335},

    {"Land_HBarrier_5_F", {34743.3, 13422.2, 0}, 8.61445},

    {"Land_HBarrier_5_F", {34749, 13421.8, 0}, 0},

    {"Land_HBarrier_5_F", {34757.9, 13421.4, 0}, 0},

    {"Land_HBarrier_1_F", {34752.1, 13423.3, 0}, 0},

    {"Land_HBarrier_1_F", {34754.9, 13423.1, 0}, 0},
    // Central camp
    {"CDF_WarfareBBarrier10x", {24410.2, 13950, 0}, 149.889},

    {"CDF_WarfareBBarrier10x", {24399, 13951.8, -4.76837e-007}, 237.755},

    {"CDF_WarfareBBarrier10x", {24390.5, 13965.2, -4.76837e-007}, 237.755},

    {"CDF_WarfareBBarrier10x", {24392.3, 13976, -4.76837e-007}, 149.889},

    {"CDF_WarfareBVehicleServicePoint", {24404.4, 13953.2, 0}, 32.7345},

    {"Land_Tyres_F", {24412.4, 13954.3, 0}, 153.335},

    {"Land_Wreck_CarDismantled_F", {24401.3, 13959.3, 0}, 289.441},

    {"Land_Wreck_Car2_F", {24396.2, 13965.4, 0}, 0},

    {"Land_Wreck_HMMWV_F", {24393, 13966.9, 0}, 329.067},

    {"Land_Tyres_F", {24389.7, 13971.8, 0}, 153.335},

    {"Land_WoodenCart_F", {24398.9, 13975.1, 0}, 0},

    {"Land_Sacks_goods_F", {24396.2, 13975.9, 0}, 0},

    {"Land_LampSolar_off_F", {24402.9, 13947.8, 0}, 0},

    {"Land_Coil_F", {24394.3, 13973.6, 0}, 0},

    {"Land_JunkPile_F", {24396.8, 13960.5, 0}, 0},

    {"Land_fuel_tank_small", {24402.3, 13950.3, 0}, 151.612},

    {"CDF_WarfareBBarrier10x", {24403.6, 13974, -4.76837e-007}, 237.755},

    {"CDF_WarfareBBarrier10x", {24413.6, 13960.4, -4.76837e-007}, 237.755},

    {"Land_Campfire_burning", {24409, 13962.9, 0}, 0},
    // West camp
    {"brownrock2", {4036.04, 19453.9, 0}, 0},
    {"brownrock3", {4051.51, 19475.8, 0}, 0},
    {"brownrock", {4032.26, 19436, 0}, 0},
    {"brownrock3", {4018.7, 19411.2, 0.00144196}, 101.649},
    {"brownrock2", {4080.9, 19486.6, -0.000320435}, 167.118},

    {"brownrock2", {4010.67, 19383.7, -0.000320435}, 167.118},
    {"brownrock3", {4007.2, 19354, -4.57764e-005}, 241.201},
    {"Land_CncBarrierMedium4_F", {4089.53, 19469, 0.00396729}, 90},

    {"Land_CncBarrierMedium4_F", {4089.53, 19461.4, 0.00396729}, 90},

    {"Land_CncBarrierMedium4_F", {4089.53, 19453.8, 0.00396729}, 90},
    {"Land_CncBarrierMedium4_F", {4089.53, 19446.2, 0.00396729}, 90},
    {"Land_CncBarrierMedium4_F", {4089.53, 19438.6, 0.00396729}, 90},
    {"Land_CncBarrierMedium4_F", {4089.53, 19431, 0.00396729}, 90},
    {"Land_CncBarrierMedium4_F", {4089.53, 19415.8, 0.00396729}, 90},

    {"Land_CncBarrierMedium4_F", {4089.53, 19408.3, 0.00396729}, 90},

    {"Land_CncBarrierMedium4_F", {4089.53, 19400.7, 0.00396729}, 90},
    {"Land_CncBarrierMedium4_F", {4089.53, 19393.1, 0.00396729}, 90},
    {"Land_CncBarrierMedium4_F", {4089.53, 19385.5, 0.00396729}, 90},
    {"Land_CncBarrierMedium4_F", {4089.53, 19377.9, 0.00396729}, 90},

    {"Land_CncBarrierMedium4_F", {4085.79, 19374.8, -0.000160217}, 180},

    {"Land_CncBarrierMedium4_F", {4078.2, 19374.8, -0.000160217}, 180},

    {"Land_CncBarrierMedium4_F", {4070.61, 19374.8, -0.000160217}, 180},

    {"Land_CncBarrierMedium4_F", {4063.01, 19374.8, -0.000160217}, 180},

    {"Land_CncBarrierMedium4_F", {4055.42, 19374.8, -0.000160217}, 180},

    {"Land_CncBarrierMedium4_F", {4047.83, 19374.8, -0.000160217}, 180},

    {"Land_CncBarrierMedium4_F", {4040.23, 19374.8, -0.000160217}, 180},

    {"Land_CncBarrierMedium4_F", {4032.64, 19374.8, -0.000160217}, 180},

    {"Land_CncBarrierMedium4_F", {4025.05, 19374.8, -0.000160217}, 180},

    {"Land_ScrapHeap_2_F", {4045.49, 19423.8, 0}, 0},

    {"WaterPump_01_sand_F", {4036.06, 19409.3, 0}, 0},

    {"Land_Bunker_F", {4048.51, 19449.7, 0}, 315.284},

    {"Land_Cargo_Patrol_V2_F", {4083.22, 19463.4, 0}, 0},

    {"Land_Communication_F", {4075.63, 19467.2, 0}, 0},

    {"Land_BarGate_F", {4087.73, 19423.3, 0.0014801}, 90, false},

    {"Land_Tank_rust_F", {4032.32, 19378, 0}, 0},

    {"Land_Tank_rust_F", {4039.04, 19377.9, 0}, 0},



    {"HMMWVWreck", {4066.81, 19391.8, 0.00606537}, 115.432},

    {"datsun02Wreck", {4075.33, 19461, -0.00206757}, 25.8429},

    {"Land_LampHalogen_off_F", {4035.6, 19406.3, 0}, 180},
    {"Land_LampHalogen_off_F", {4045.78, 19439.3, 0}, 180},
    // Wind Turbines
    {"Land_wpp_Turbine_V2_F", {17471.5, 31880, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {17487.7, 31607.5, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {17607.6, 31660.4, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {19344, 36134.1, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {19599.9, 36089.8, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {22239.7, 33868.5, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {21072.6, 34764.6, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {21069.9, 34839, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {21951.5, 32894.8, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {21939.6, 32939, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {21932.2, 33013.1, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {14230.9, 31117.5, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {14189.9, 31127.2, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {14142, 31139.2, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {28899.5, 35283.1, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {28918.5, 35259, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {31014.7, 32861.8, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {28984.4, 33972.4, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {30717.7, 32027.4, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {30770.3, 31948.5, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {30850, 31818.1, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {30821.7, 28701.9, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {30872.5, 28676.2, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {30934.8, 28626.8, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {30998.8, 28582.2, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {36173.5, 23892.8, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {36028.7, 23826.4, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {35866.8, 23797.8, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {33890.9, 22472.2, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {33905.6, 22415.6, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {33920.6, 22367.7, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {26318.3, 19100.2, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {26368.5, 19093.3, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {26423.3, 19083, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {8701.28, 19761.6, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {8667.67, 19710.9, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {7801.43, 19285.2, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {7745.98, 19240.7, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {7650.39, 19168.8, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {7541.71, 19073.1, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {5917.63, 12370, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {6018.31, 12440.5, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {5779.98, 12304, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {10988, 15244.2, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {10958.5, 15150.6, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {10902.6, 15042.6, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {20512.2, 14845.3, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {20513.1, 14800.1, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {34095.3, 16299.6, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {34092.8, 16265.5, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {34078.4, 16233.9, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {38268.9, 15084.6, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {37788.9, 15954.8, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {37788.3, 16018.3, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {37803.2, 16137.4, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {37837.1, 16315.4, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {34510.6, 11062.3, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {34476.8, 11119.1, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {34411.4, 11204.5, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {33540.8, 8230.01, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {33506.2, 8259.1, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {33479.3, 8289.11, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {33615.6, 3925.49, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {33582.5, 4029.25, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {33521.1, 4159.21, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {31983.5, 3752.43, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {32015.1, 3735.57, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {26768.4, 9460.39, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {26769.5, 9419.41, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {26766.7, 9386.49, 0}, 0},
    {"Land_wpp_Turbine_V2_F", {26766.7, 9348.41, 0}, 0},
    // Garbage
    {"Land_GarbagePallet_F", {16006.4, 33369.4, 0}, 0},
    {"Land_GarbagePallet_F", {16160.7, 33533.7, 0}, 0},
    {"Land_GarbagePallet_F", {16270.2, 33564.7, 0}, 0},
    {"Land_GarbagePallet_F", {16199.1, 33656.3, 0}, 0},
    {"Land_GarbagePallet_F", {16159.8, 33700.5, 0}, 0},
    {"Land_GarbagePallet_F", {16160.4, 33792.6, 0}, 0},
    {"Land_GarbagePallet_F", {16372.1, 33663.1, 0}, 0},
    {"Land_GarbagePallet_F", {16472.5, 33565.5, 0}, 0},
    {"Land_GarbagePallet_F", {16583.4, 33479.9, 0}, 0},
    {"Land_GarbagePallet_F", {16341, 33408, 0}, 0},
    {"Land_GarbagePallet_F", {15891.7, 33213.4, 0}, 0},
    {"Land_GarbagePallet_F", {15807.9, 33308.7, 0}, 0},
    {"Land_GarbagePallet_F", {15696.3, 33408.9, 0}, 0},
    {"Land_GarbagePallet_F", {15612.7, 33222.6, 0}, 0},
    {"Land_GarbagePallet_F", {15680.1, 33197.9, 0}, 0},
    {"Land_GarbagePallet_F", {15741.5, 33224.2, 0}, 0},
    {"Land_GarbagePallet_F", {15773.9, 33093.9, 0}, 0},
    {"Land_GarbageBags_F", {15682.2, 33156.9, 0.0492201}, 0},
    {"Land_GarbageBags_F", {15770.5, 33176, 0}, 0},
    {"Land_GarbageBags_F", {15849.4, 33225.3, 0}, 0},
    {"Land_GarbageBags_F", {15912.5, 33288.8, 0}, 0},
    {"Land_GarbageBags_F", {15965.5, 33299.1, 0}, 0},
    {"Land_GarbageBags_F", {15984.7, 33287.8, 0}, 0},
    {"Land_GarbageBags_F", {16025.8, 33351, 0}, 0},
    {"Land_GarbageBags_F", {16027.8, 33324.1, 0}, 0},
    {"Land_GarbageBags_F", {16044.1, 33384.1, 0}, 0},
    {"Land_GarbageBags_F", {16108.8, 33392, 0}, 0},
    {"Land_GarbageBags_F", {16442.9, 33401.3, 0}, 0},
    {"Land_GarbageBags_F", {16507.2, 33508.4, 0}, 0},
    {"Land_GarbageBags_F", {16662.2, 33590.5, 0}, 0},
    {"Land_GarbageBags_F", {17112.8, 33379, 0}, 0},
    {"Land_GarbageBags_F", {17574, 33024.1, 0}, 0},
    {"Land_GarbageBags_F", {17562.1, 33019.4, 0}, 0},
    {"Land_GarbageBags_F", {17475.1, 34218.1, 0}, 0},
    {"Land_GarbageBags_F", {17476.3, 34211.5, 0}, 100.455},
    {"Land_GarbageBags_F", {17752.2, 34386.1, 0}, 0},
    {"Land_GarbageBags_F", {15941.7, 33289.9, 0}, 0},
    {"Land_GarbageBags_F", {16000.5, 33357, 0}, 0},
    {"Land_GarbageBags_F", {15914.8, 33417.1, 0}, 0},
    {"Land_GarbageBags_F", {28990.7, 36639.3, 0}, 0},
    {"Land_GarbageBags_F", {29018.6, 36664.5, 0}, 0},
    {"Land_GarbagePallet_F", {28996.5, 36691.7, 0}, 0},
    {"Land_GarbagePallet_F", {28474.8, 35269.2, 0}, 0},
    {"Land_GarbagePallet_F", {28412.9, 35236, 0}, 0},
    {"Land_GarbagePallet_F", {28478.1, 35173.9, 0}, 0},
    {"Land_GarbagePallet_F", {28435.3, 35152.4, 0}, 0},
    {"Land_GarbageBags_F", {28402.2, 35171.2, 0}, 0},
    {"Land_GarbageBags_F", {28386.6, 35257.9, 0}, 0},
    {"Land_GarbageBags_F", {28442.9, 35256.5, 0}, 0},
    {"Land_GarbageBags_F", {28537.4, 35170.3, 0}, 0},
    {"Land_GarbageBags_F", {29050, 34044.7, 0}, 0},
    {"Land_GarbageBags_F", {29047.2, 34183.7, 0}, 0},
    {"Land_GarbageBags_F", {29176.9, 34151.5, 0}, 0},
    {"Land_GarbagePallet_F", {29079.6, 34106.7, 0}, 0},
    {"Land_GarbagePallet_F", {29127.1, 34037.6, 0}, 0},
    {"Land_GarbagePallet_F", {29018, 33994, 0}, 0},
    {"Land_GarbagePallet_F", {10134.4, 29852.3, 0}, 0},
    {"Land_GarbagePallet_F", {10122.6, 29817.3, 0}, 0},
    {"Land_GarbagePallet_F", {10258.6, 29891.3, 0}, 0},
    {"Land_GarbageBags_F", {10250.8, 29871.7, 0}, 0},
    {"Land_GarbageBags_F", {31587.6, 30964, 0}, 0},
    {"Land_GarbageBags_F", {31691.8, 30952.4, 0}, 0},
    {"Land_GarbagePallet_F", {31633.9, 30911.3, 0}, 0},
    {"Land_GarbagePallet_F", {31607.5, 31022.2, 0}, 0},
    {"Land_GarbagePallet_F", {31795.9, 29664.1, 0}, 0},
    {"Land_GarbagePallet_F", {31885, 29613, 0}, 0},
    {"Land_GarbagePallet_F", {31892.8, 29681.6, 0}, 0},
    {"Land_GarbagePallet_F", {31850.2, 29784.6, 0}, 0},
    {"Land_GarbagePallet_F", {31964.2, 29758.1, 0}, 0},
    {"Land_GarbagePallet_F", {32084.3, 29756.7, 0}, 0},
    {"Land_GarbagePallet_F", {32114.2, 29986.8, 0}, 0},
    {"Land_GarbagePallet_F", {32076.9, 29996.7, 0}, 0},
    {"Land_GarbageBags_F", {32150.1, 30012.7, 0}, 0},
    {"Land_GarbageBags_F", {32086.7, 29861.1, 0}, 0},
    {"Land_GarbageBags_F", {32234.6, 29673.1, 0}, 0},
    {"Land_GarbageBags_F", {32111.2, 29685.6, 0}, 0},
    {"Land_GarbageBags_F", {31958.8, 29606.8, 0}, 0},
    {"Land_GarbageBags_F", {31908.6, 29764.1, 0}, 0},
    {"Land_GarbageBags_F", {32015.1, 29880, 0}, 0},
    {"Land_GarbageBags_F", {31996.5, 30012.9, 0}, 0},
    {"Land_GarbageBags_F", {26832, 27917, 0}, 0},
    {"Land_GarbageBags_F", {26788.1, 28057.1, 0}, 0},
    {"Land_GarbageBags_F", {26730.8, 27992.9, 0}, 0},
    {"Land_GarbagePallet_F", {26662.2, 28006.6, 0}, 0},
    {"Land_GarbagePallet_F", {26753.8, 28075.2, 0}, 0},
    {"Land_GarbagePallet_F", {26978.6, 28287.1, 0}, 0},
    {"Land_GarbagePallet_F", {26755.8, 27996.7, 0}, 0},
    {"Land_GarbagePallet_F", {26748.2, 28069.8, 0}, 0},
    {"Land_GarbagePallet_F", {22379.8, 25550.3, 0}, 0},
    {"Land_GarbageBags_F", {22442.3, 25553.1, 0}, 0},
    {"Land_GarbageBags_F", {22234.9, 25563.4, 0}, 0},
    {"Land_GarbageBags_F", {22052.5, 25562.4, 0}, 0},
    {"Land_GarbagePallet_F", {22030, 25529.5, 0}, 0},
    {"Land_GarbagePallet_F", {22036.5, 25491.3, 0}, 0},
    {"Land_GarbagePallet_F", {21954.6, 25537.3, 0}, 0},
    {"Land_GarbageBags_F", {21886.1, 25522, 0}, 0},
    {"Land_GarbageBags_F", {21880.1, 25726.3, 0}, 0},
    {"Land_GarbageBags_F", {21888.6, 25783.4, 0}, 0},
    {"Land_GarbageBags_F", {21951.9, 25777.9, 0}, 0},
    {"Land_GarbageBags_F", {21941.6, 25718.7, 0}, 0},
    {"Land_GarbagePallet_F", {21920.2, 25759.7, 0}, 0},
    {"Land_GarbagePallet_F", {21983.7, 25709.5, 0}, 0},
    {"Land_GarbagePallet_F", {22027.1, 25766.2, 0}, 0},
    {"Land_GarbageBags_F", {22045.6, 25701.1, 0}, 0},
    {"Land_GarbageBags_F", {22156.3, 25673.8, 0}, 0},
    {"Land_GarbageBags_F", {22239.9, 25568.9, 0}, 0},
    {"Land_GarbageBags_F", {22047.7, 25431.9, 0}, 0},
    {"Land_GarbageBags_F", {22649.3, 24806.1, 0}, 0},
    {"Land_GarbagePallet_F", {22645.2, 24807.9, 0}, 0},
    {"Land_GarbageContainer_open_F", {22653.6, 24811.2, 0}, 255.455},
    {"Land_GarbagePallet_F", {19874.5, 24373.1, 0}, 0},
    {"Land_GarbagePallet_F", {19842.8, 24526.4, 0}, 0},
    {"Land_GarbageBags_F", {19795.4, 24402.3, 0}, 0},
    {"Land_GarbageBags_F", {19642.3, 24561.7, 0}, 0},
    {"Land_GarbageBags_F", {19602.2, 24672.1, 0}, 0},
    {"Land_GarbageBags_F", {19650.6, 24086.4, 0}, 0},
    {"Land_GarbagePallet_F", {19635.1, 24036.9, 0}, 0},
    {"Land_GarbagePallet_F", {19517.5, 24056.6, 0}, 0},
    {"Land_GarbagePallet_F", {19486.3, 23915.6, 0}, 0},
    {"Land_GarbageBags_F", {19410.6, 23951.5, 0}, 0},
    {"Land_GarbageBags_F", {19393.8, 23963.9, 0}, 0},
    {"Land_GarbageBags_F", {20033, 24253.9, 0}, 0},
    {"Land_GarbageBags_F", {19686.1, 24085.8, 0}, 0},
    {"Land_GarbageBags_F", {4064.7, 17183, 0}, 0},
    {"Land_GarbageBags_F", {4062.15, 17120, 0}, 0},
    {"Land_GarbageBags_F", {4027.97, 17167, 0}, 0},
    {"Land_GarbageBags_F", {4031.36, 17304.2, 0}, 0},
    {"Land_GarbageBags_F", {4079.91, 17320.7, 0}, 0},
    {"Land_GarbageBags_F", {4050, 17394.6, 0}, 0},
    {"Land_GarbageBags_F", {4076.14, 17385.1, 0}, 0},
    {"Land_GarbagePallet_F", {4082.06, 17359.7, 0}, 0},
    {"Land_GarbagePallet_F", {4039.94, 17411.9, 0}, 0},
    {"Land_GarbagePallet_F", {4037.43, 17340, 0}, 0},
    {"Land_GarbagePallet_F", {4044.81, 17578.5, 0}, 0},
    {"Land_GarbagePallet_F", {4075.01, 17644.7, 0}, 0},
    {"Land_GarbagePallet_F", {3987.72, 17635.1, 0}, 0},
    {"Land_GarbagePallet_F", {4048.52, 17818.6, 0}, 0},
    {"Land_GarbagePallet_F", {4102.45, 17846.7, 0}, 0},
    {"Land_GarbagePallet_F", {4104.42, 17787.8, 0}, 0},
    {"Land_GarbagePallet_F", {4140.62, 17791.5, 0}, 0},
    {"Land_GarbagePallet_F", {4194, 17787.2, 0}, 0},
    {"Land_GarbagePallet_F", {4204.49, 17820.7, 0}, 0},
    {"Land_GarbageBags_F", {4061.74, 17790.9, 0}, 0},
    {"Land_GarbageBags_F", {4031.2, 17850.8, 0}, 0},
    {"Land_GarbageBags_F", {4075.22, 17816.1, 0}, 0},
    {"Land_GarbageBags_F", {4149.92, 17824.9, 0}, 0},
    {"Land_GarbageBags_F", {4318.3, 17845.6, 0}, 0},
    {"Land_GarbageBags_F", {4297.62, 17788.2, 0}, 0},
    {"Land_GarbageBags_F", {4412.56, 17831.9, 0}, 0},
    {"Land_GarbageBags_F", {4420.85, 17780.8, 0}, 0},
    {"Land_GarbageBags_F", {4512.08, 17792.2, 0}, 0},
    {"Land_GarbageBags_F", {4577.07, 17757.3, 0}, 0},
    {"Land_GarbageBags_F", {4579.15, 17852, 0}, 0},
    {"Land_GarbageBags_F", {4572.17, 17980.6, 0}, 0},
    {"Land_GarbageBags_F", {4696.2, 18058.1, 0}, 0},
    {"Land_GarbageBags_F", {4753.67, 18105.8, 0}, 0},
    {"Land_GarbageBags_F", {4765.8, 18045.2, 0}, 0},
    {"Land_GarbageBags_F", {4808.09, 18014.5, 0}, 0},
    {"Land_GarbageBags_F", {4693.54, 18349.5, 0}, 0},
    {"Land_GarbageBags_F", {4629.09, 18349.5, 0}, 0},
    {"Land_GarbageBags_F", {4589.01, 18390.8, 0}, 0},
    {"Land_GarbagePallet_F", {4593.95, 18343.7, 0}, 0},
    {"Land_GarbagePallet_F", {4661.78, 18363.5, 0}, 0},
    {"Land_GarbagePallet_F", {4465.32, 18462.5, 0}, 0},
    {"Land_GarbagePallet_F", {4826.29, 18348.9, 0}, 0},
    {"Land_GarbagePallet_F", {5469.15, 18432.7, 0}, 0},
    {"Land_GarbagePallet_F", {5473.77, 18476.4, 0}, 0},
    {"Land_GarbagePallet_F", {5503.79, 18482.5, 0}, 0},
    {"Land_GarbageBags_F", {5511.98, 18480.7, 0}, 0},
    {"Land_GarbageBags_F", {5534.63, 18455.4, 0}, 0},
    {"Land_GarbageBags_F", {5534.85, 18501.4, 0}, 0},
    {"Land_GarbageBags_F", {5613.3, 18486.7, 0}, 0},
    {"Land_GarbagePallet_F", {5610.03, 18482.6, 0}, 0},
    {"Land_GarbagePallet_F", {5771.71, 18582.4, 0}, 0},
    {"Land_GarbagePallet_F", {5738.36, 18607.2, 0}, 0},
    {"Land_GarbagePallet_F", {5738.81, 18683.4, 0}, 0},
    {"Land_GarbagePallet_F", {5685.25, 18709.5, 0}, 0},
    {"Land_GarbageBags_F", {5685.22, 18722.8, 0}, 0},
    {"Land_GarbageBags_F", {5578.59, 18803.7, 0}, 0},
    {"Land_GarbageBags_F", {5536.85, 18688.1, 0}, 0},
    {"Land_GarbageBags_F", {4897.73, 17874.4, 0}, 0},
    {"Land_GarbageBags_F", {4818.78, 17806, 0}, 0},
    {"Land_GarbageBags_F", {4733.5, 17796.2, 0}, 0},
    {"Land_GarbagePallet_F", {4725.9, 17743.1, 0}, 0},
    {"Land_GarbagePallet_F", {27680, 16915.8, 0}, 0},
    {"Land_GarbagePallet_F", {27603, 16941.4, 0}, 0},
    {"Land_GarbagePallet_F", {27679.3, 17018.1, 0}, 0},
    {"Land_GarbagePallet_F", {27766.7, 17014.2, 0}, 0},
    {"Land_GarbagePallet_F", {27779.7, 17000.7, 0}, 0},
    {"Land_GarbageBags_F", {27750.6, 16942.8, 0}, 0},
    {"Land_GarbageBags_F", {27689.1, 16902.5, 0}, 0},
    {"Land_GarbageBags_F", {27570.5, 17025.5, 0}, 0},
    {"Land_GarbageBags_F", {27539.6, 16993, 0}, 0},
    {"Land_GarbageBags_F", {35461, 17257.9, 0}, 0},
    {"Land_GarbageBags_F", {35410.8, 17310, 0}, 0},
    {"Land_GarbageBags_F", {34452.9, 22483.3, 0}, 0},
    {"Land_GarbageBags_F", {34254.7, 22517, 0}, 0},
    {"Land_GarbageBags_F", {34412.8, 22622.6, 0}, 0},
    {"Land_GarbagePallet_F", {34453, 22558.8, 0}, 0},
    {"Land_GarbagePallet_F", {37537.8, 19762.6, 0}, 0},
    {"Land_GarbagePallet_F", {37647.5, 19905.9, 0}, 0},
    {"Land_GarbagePallet_F", {37650.8, 19762.4, 0}, 0},
    {"Land_GarbagePallet_F", {37682.1, 19719.2, 0}, 0},
    {"Land_GarbagePallet_F", {37826.8, 19887.6, 0}, 0},
    {"Land_GarbagePallet_F", {37899.5, 19801.4, 0}, 0},
    {"Land_GarbagePallet_F", {37855.2, 19799.8, 0}, 0},
    {"Land_GarbagePallet_F", {38006.1, 19889.2, 0}, 0},
    {"Land_GarbagePallet_F", {38127.5, 20203.3, 0}, 0},
    {"Land_GarbagePallet_F", {38324.9, 20110.7, 0}, 0},
    {"Land_GarbagePallet_F", {38403.3, 20119, 0}, 0},
    {"Land_GarbagePallet_F", {38491.3, 20171.4, 0}, 0},
    {"Land_GarbagePallet_F", {38541.1, 19965.2, 0}, 0},
    {"Land_GarbagePallet_F", {38205.8, 19914.4, 0}, 0},
    {"Land_GarbagePallet_F", {38050.1, 19772.2, 0}, 0},
    {"Land_GarbageBags_F", {37907, 19762.8, 0}, 0},
    {"Land_GarbageBags_F", {37866.3, 19799.7, 0}, 0},
    {"Land_GarbageBags_F", {37816.2, 19994.2, 0}, 0},
    {"Land_GarbageBags_F", {37905.5, 20134.5, 0}, 0},
    {"Land_GarbageBags_F", {38172.9, 20060.5, 0}, 0},
    {"Land_GarbageBags_F", {38206.9, 20655.1, 0}, 0},
    {"Land_GarbageBags_F", {37932.6, 20492.2, 0}, 0},
    {"Land_GarbageBags_F", {38264.5, 19678.9, 0}, 0},
    {"Land_GarbageBags_F", {38254, 19606, 0}, 0},
    {"Land_GarbageBags_F", {38449.9, 19679.8, 0}, 0},
    {"Land_GarbageBags_F", {38585.8, 19663, 0}, 0},
    {"Land_GarbageBags_F", {38624.3, 19591, 0}, 0},
    {"Land_GarbageBags_F", {38699.7, 19555.9, 0}, 0},
    {"Land_GarbageBags_F", {38870.1, 19502.4, 0}, 0},
    {"Land_GarbageBags_F", {38807.2, 19685, 0}, 0},
    {"Land_GarbageBags_F", {38602.3, 19531.5, 0}, 0},
    {"Land_GarbageBags_F", {38378.3, 19341.6, 0}, 0},
    {"Land_GarbageBags_F", {38744.8, 19310.7, 0}, 0},
    {"Land_GarbageBags_F", {38730.5, 19140.8, 0}, 0},
    {"Land_GarbageBags_F", {38832.3, 19168.7, 0}, 0},
    {"Land_GarbageBags_F", {38865.1, 18942.4, 0}, 0},
    {"Land_GarbageBags_F", {38641.9, 18900.4, 0}, 0},
    {"Land_GarbageBags_F", {38549.8, 18906.3, 0}, 0},
    {"Land_GarbagePallet_F", {38546.4, 18907.2, 0}, 0},
    {"Land_GarbagePallet_F", {38536.6, 19006.9, 0}, 0},
    {"Land_GarbagePallet_F", {31340.7, 16766.3, 0}, 0},
    {"Land_GarbagePallet_F", {31348.8, 16752.3, 0}, 0},
    {"Land_GarbagePallet_F", {31323.2, 16737.5, 0}, 0},
    {"Land_GarbageBags_F", {31338.1, 16746.7, 0}, 0},
    {"Land_GarbageBags_F", {31293.7, 16732.1, 0}, 0},
    {"Land_GarbageBags_F", {31278.3, 16751.3, 0}, 0},
    {"Land_GarbageBags_F", {33728.4, 15571.1, 0}, 0},
    {"Land_GarbageBags_F", {33762.2, 15699.3, 0}, 0},
    {"Land_GarbagePallet_F", {33863, 15673.3, 0}, 0},
    {"Land_GarbagePallet_F", {33834.3, 15641.2, 0}, 0},
    {"Land_GarbagePallet_F", {33843.8, 15746.9, 0}, 0},
    {"Land_GarbagePallet_F", {36490.1, 13151.5, 0}, 0},
    {"Land_GarbagePallet_F", {36658.9, 13150.4, 0}, 0},
    {"Land_GarbagePallet_F", {36836.9, 13019.4, 0}, 0},
    {"Land_GarbagePallet_F", {36895, 13121.7, 0}, 0},
    {"Land_GarbagePallet_F", {36939, 12956.5, 0}, 0},
    {"Land_GarbagePallet_F", {36956.4, 12861.1, 0}, 0},
    {"Land_GarbageBags_F", {36953.5, 12857.3, 0}, 0},
    {"Land_GarbageBags_F", {36930.7, 12740.6, 0}, 0},
    {"Land_GarbageBags_F", {36812.5, 12696.3, 0}, 0},
    {"Land_GarbageBags_F", {36747.3, 12775.4, 0}, 0},
    {"Land_GarbageBags_F", {36555.7, 12861.3, 0}, 0},
    {"Land_GarbageBags_F", {36459.1, 12901.5, 0}, 0},
    {"Land_GarbageBags_F", {36382.3, 12841.8, 0}, 0},
    {"Land_GarbageBags_F", {36423.8, 12748.5, 0}, 0},
    {"Land_GarbageBags_F", {36436.4, 12792.8, 0}, 0},
    {"Land_GarbageBags_F", {35839.5, 12996.8, 0}, 0},
    {"Land_GarbageBags_F", {35337.8, 8528.21, 0}, 0},
    {"Land_GarbageBags_F", {35369.4, 8443.14, 0}, 0},
    {"Land_GarbagePallet_F", {35383.3, 8445.58, 0}, 0},
    {"Land_GarbagePallet_F", {35336.7, 8372.79, 0}, 0},
    {"Land_GarbagePallet_F", {35305.1, 8410.81, 0}, 0},
    {"Land_GarbagePallet_F", {35352.3, 8563.8, 0}, 0},
    {"Land_GarbagePallet_F", {35438.6, 8578.18, 0}, 0},
    {"Land_GarbagePallet_F", {35391.6, 8620.26, 0}, 0},
    {"Land_GarbagePallet_F", {35432.4, 8624.22, 0}, 0},
    {"Land_GarbageBags_F", {35419.9, 8619.09, 0}, 0},
    {"Land_GarbageBags_F", {35493.4, 8641.29, 0}, 0},
    {"Land_GarbageBags_F", {35451.6, 8456.98, 0}, 0},
    {"Land_GarbageBags_F", {31226.4, 11357.4, 0}, 0},
    {"Land_GarbageBags_F", {31328.7, 11287.9, 0}, 0},
    {"Land_GarbageBags_F", {31394.7, 11183.6, 0}, 0},
    {"Land_GarbageBags_F", {31503.5, 11044.3, 0}, 0},
    {"Land_GarbagePallet_F", {31499.4, 11053.7, 0}, 0},
    {"Land_GarbagePallet_F", {31242.1, 11285.7, 0}, 0},
    {"Land_GarbagePallet_F", {31298.9, 11327.8, 0}, 0},
    {"Land_GarbagePallet_F", {31164.2, 11274.4, 0}, 0},
    {"Land_GarbagePallet_F", {31213.4, 11164.3, 0}, 0},
    {"Land_GarbageBags_F", {31137.6, 11168.4, 0}, 0},
    {"Land_GarbageBags_F", {31139.3, 10954.3, 0}, 0},
    {"Land_GarbagePallet_F", {31134.7, 10955.9, 0}, 0},
    {"Land_GarbagePallet_F", {31131.5, 10844.8, 0}, 0},
    {"Land_GarbagePallet_F", {31109.5, 10755.7, 0}, 0},
    {"Land_GarbagePallet_F", {31132.2, 10692.8, 0}, 0},
    {"Land_GarbagePallet_F", {31117.9, 10550.6, 0}, 0},
    {"Land_GarbagePallet_F", {31122.5, 10522.6, 0}, 0},
    {"Land_GarbageBags_F", {31074.6, 10523.1, 0}, 0},
    {"Land_GarbageBags_F", {31012.7, 10533.4, 0}, 0},
    {"Land_GarbageBags_F", {30896.5, 10686.5, 0}, 0},
    {"Land_GarbageBags_F", {31032.2, 10718.2, 0}, 0},
    {"Land_GarbageBags_F", {30728.4, 10657.2, 0}, 0},
    {"Land_GarbageBags_F", {30699.5, 10757.5, 0}, 0},
    {"Land_GarbageBags_F", {30777.6, 10756.4, 0}, 0},
    {"Land_GarbageBags_F", {30785.1, 10293.1, 0}, 0},
    {"Land_GarbageBags_F", {30818.4, 10289.3, 0}, 0},
    {"Land_GarbageBags_F", {30939.4, 10220.3, 0}, 0},
    {"Land_GarbageBags_F", {31049.3, 10225.9, 0}, 0},
    {"Land_GarbagePallet_F", {31159.5, 10241.9, 0}, 0},
    {"Land_GarbagePallet_F", {31171.7, 10167.3, 0}, 0},
    {"Land_GarbagePallet_F", {31505.7, 9931.36, 0}, 0},
    {"Land_GarbagePallet_F", {31500.9, 9720.38, 0}, 0},
    {"Land_GarbagePallet_F", {31511, 9679, 0}, 0},
    {"Land_GarbagePallet_F", {31619.3, 9655.18, 0}, 0},
    {"Land_GarbagePallet_F", {31826.2, 9061.1, 0}, 0},
    {"Land_GarbagePallet_F", {31822.7, 9372.9, 0}, 0},
    {"Land_GarbagePallet_F", {26183.5, 11081.5, 0}, 0},
    {"Land_GarbagePallet_F", {26156.1, 11119.5, 0}, 0},
    {"Land_GarbagePallet_F", {25091.2, 12591.2, 0}, 0},
    {"Land_GarbagePallet_F", {25048.8, 12788.3, 0}, 0},
    {"Land_GarbageBags_F", {25042.9, 12774.5, 0}, 0},
    {"Land_GarbageBags_F", {25174.9, 12808.7, 0}, 0},
    {"Land_GarbageBags_F", {25178.5, 12770.1, 0}, 0},
    {"Land_GarbageBags_F", {25290.5, 12753.1, 0}, 0},
    {"Land_GarbageBags_F", {25234.2, 12842.6, 0}, 0},
    {"Land_GarbageBags_F", {25071, 12774.6, 0}, 0},
    {"Land_GarbagePallet_F", {25075.9, 12768.5, 0}, 0},
    {"Land_GarbagePallet_F", {24874.4, 12508.3, 0}, 0},
    {"Land_GarbagePallet_F", {24801.1, 12408, 0}, 0},
    {"Land_GarbagePallet_F", {24725.8, 12496.5, 0}, 0},
    {"Land_GarbagePallet_F", {20747.8, 12732.2, 0}, 0},
    {"Land_GarbagePallet_F", {20732.6, 12901.8, 0}, 0},
    {"Land_GarbagePallet_F", {20862.9, 12672, 0}, 0},
    {"Land_GarbageBags_F", {20916.4, 12695.6, 0}, 0}
	};
	staticNpcPos[] = {
			// North
			{ "C_man_hunter_1_F", { 19031.8, 33967, 0 }, 275 },
			// East
			{ "C_man_hunter_1_F", { 34757.4, 13432.1, 0 }, 313.34},
			// Central
			{ "C_man_hunter_1_F", { 24407.3, 13957.4, 0 }, 231.976},
			// West
			{ "C_man_hunter_1_F", { 4077.59, 19458.2, 0 }, 93.5839  }
	};
};
