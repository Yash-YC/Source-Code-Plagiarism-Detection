#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100000];

bool getn(int *n)
{
	char ch = getchar();
	while(!(ch <= '9' && ch >= '0')){
		if(ch == '\n'){
			return false;
		}
		ch = getchar();
	}
	*n = 0;
	while(ch <= '9' && ch >= '0'){
		*n = 10 * (*n) + ch - '0';
		ch = getchar();
	}
	if(ch == '\n'){
		return false;
	}
	return true;
}

int main()
{
//	freopen("")
	freopen("check.txt", "w", stdout);

	a[4] = 2;a[5] = 2;a[6] = 2;a[7] = 2;a[8] = 3;a[9] = 3;a[10] = 3;a[11] = 3;a[12] = 3;a[13] = 3;a[14] = 3;a[15] = 3;a[16] = 2;a[17] = 2;a[18] = 2;a[19] = 2;a[20] = 2;a[21] = 2;a[22] = 2;
	a[23] = 2;a[24] = 3;a[25] = 3;a[26] = 3;a[27] = 3;a[28] = 3;a[29] = 3;a[30] = 3;a[31] = 3;a[32] = 5;a[33] = 5;a[34] = 5;a[35] = 5;a[36] = 5;a[37] = 5;a[38] = 5;a[39] = 5;a[40] = 23;a[41] = 23;a[42] = 23;a[43] = 23;a[44] = 23;
	a[45] = 23;a[46] = 23;a[47] = 23;a[48] = 5;a[49] = 5;a[50] = 5;a[51] = 5;a[52] = 5;a[53] = 5;a[54] = 5;a[55] = 5;a[56] = 23;a[57] = 23;a[58] = 23;a[59] = 23;a[60] = 23;a[61] = 23;a[62] = 23;a[63] = 23;a[64] = 6;a[65] = 6;a[66] = 6;a[67] = 6;a[68] = 6;a[69] = 6;a[70] = 6;a[71] = 6;a[72] = 79;a[73] = 79;a[74] = 79;a[75] = 79;a[76] = 79;a[77] = 79;a[78] = 79;a[79] = 79;a[80] = 6;a[81] = 6;a[82] = 6;a[83] = 6;a[84] = 6;a[85] = 6;a[86] = 6;a[87] = 6;a[88] = 79;a[89] = 79;a[90] = 79;a[91] = 79;a[92] = 79;a[93] = 79;a[94] = 79;a[95] = 79;a[96] = 49;a[97] = 49;a[98] = 49;a[99] = 49;a[100] = 49;a[101] = 49;
	a[102] = 49;a[103] = 49;a[104] = 79;a[105] = 79;a[106] = 79;a[107] = 79;a[108] = 79;a[109] = 79;a[110] = 79;a[111] = 79;a[112] = 49;a[113] = 49;a[114] = 49;a[115] = 49;a[116] = 49;a[117] = 49;a[118] = 49;a[119] = 49;a[120] = 79;a[121] = 79;a[122] = 79;a[123] = 79;a[124] = 79;a[125] = 79;a[126] = 79;a[127] = 79;a[128] = 7;a[129] = 7;a[130] = 7;a[131] = 7;a[132] = 7;a[133] = 7;a[134] = 7;a[135] = 7;a[136] = 143;a[137] = 143;a[138] = 143;a[139] = 143;a[140] = 143;a[141] = 143;a[142] = 143;a[143] = 143;a[144] = 7;a[145] = 7;a[146] = 7;a[147] = 7;a[148] = 7;a[149] = 7;a[150] = 7;a[151] = 7;a[152] = 143;a[153] = 143;a[154] = 143;a[155] = 143;a[156] = 143;a[157] = 143;a[158] = 143;a[159] = 143;a[160] = 7;a[161] = 7;a[162] = 7;a[163] = 7;
	a[164] = 7;a[165] = 7;a[166] = 7;a[167] = 7;a[168] = 143;a[169] = 143;a[170] = 143;a[171] = 143;a[172] = 143;a[173] = 143;a[174] = 143;a[175] = 143;a[176] = 7;a[177] = 7;a[178] = 7;a[179] = 7;
	a[180] = 7;a[181] = 7;a[182] = 7;a[183] = 7;a[184] = 143;a[185] = 143;a[186] = 143;a[187] = 143;a[188] = 143;a[189] = 143;a[190] = 143;a[191] = 143;a[192] = 49;a[193] = 49;a[194] = 49;a[195] = 49;a[196] = 49;a[197] = 49;a[198] = 49;a[199] = 49;a[200] = 2207;a[201] = 2207;a[202] = 2207;a[203] = 2207;a[204] = 2207;a[205] = 2207;a[206] = 2207;a[207] = 2207;a[208] = 49;a[209] = 49;a[210] = 49;a[211] = 49;a[212] = 49;a[213] = 49;a[214] = 49;a[215] = 49;a[216] = 2207;a[217] = 2207;a[218] = 2207;a[219] = 2207;a[220] = 2207;a[221] = 2207;a[222] = 2207;a[223] = 2207;a[224] = 49;a[225] = 49;a[226] = 49;a[227] = 49;a[228] = 49;a[229] = 49;a[230] = 49;a[231] = 49;a[232] = 2207;
	a[233] = 2207;a[234] = 2207;a[235] = 2207;a[236] = 2207;a[237] = 2207;a[238] = 2207;a[239] = 2207;a[240] = 49;a[241] = 49;
	a[242] = 49;a[243] = 49;a[244] = 49;a[245] = 49;a[246] = 49;a[247] = 49;a[248] = 2207;a[249] = 2207;a[250] = 2207;a[251] = 2207;a[252] = 2207;
	a[253] = 2207;a[254] = 2207;a[255] = 2207;a[256] = 8;a[257] = 8;a[258] = 8;a[259] = 8;a[260] = 8;a[261] = 8;a[262] = 8;a[263] = 8;a[264] = 27;a[265] = 27;a[266] = 27;a[267] = 27;a[268] = 27;a[269] = 27;a[270] = 27;a[271] = 27;a[272] = 8;a[273] = 8;a[274] = 8;a[275] = 8;a[276] = 8;a[277] = 8;a[278] = 8;a[279] = 8;a[280] = 27;a[281] = 27;a[282] = 27;a[283] = 27;a[284] = 27;a[285] = 27;a[286] = 27;a[287] = 27;a[288] = 27;a[289] = 27;a[290] = 27;a[291] = 27;a[292] = 27;a[293] = 27;a[294] = 27;a[295] = 27;a[296] = 27;a[297] = 27;a[298] = 27;a[299] = 27;a[300] = 27;a[301] = 27;a[302] = 27;a[303] = 27;a[304] = 27;a[305] = 27;a[306] = 27;a[307] = 27;a[308] = 27;a[309] = 27;a[310] = 27;a[311] = 27;a[312] = 27;a[313] = 27;a[314] = 27;a[315] = 27;a[316] = 27;a[317] = 27;a[318] = 27;a[319] = 27;a[320] = 216;
	a[321] = 216;a[322] = 216;a[323] = 216;a[324] = 216;a[325] = 216;a[326] = 216;a[327] = 216;a[328] = 3879;a[329] = 3879;a[330] = 3879;a[331] = 3879;a[332] = 3879;a[333] = 3879;a[334] = 3879;a[335] = 3879;a[336] = 216;a[337] = 216;a[338] = 216;a[339] = 216;
	a[340] = 216;a[341] = 216;a[342] = 216;a[343] = 216;a[344] = 3879;a[345] = 3879;a[346] = 3879;a[347] = 3879;a[348] = 3879;a[349] = 3879;a[350] = 3879;a[351] = 3879;a[352] = 1975;a[353] = 1975;a[354] = 1975;a[355] = 1975;a[356] = 1975;a[357] = 1975;a[358] = 1975;a[359] = 1975;a[360] = 3879;a[361] = 3879;a[362] = 3879;a[363] = 3879;a[364] = 3879;a[365] = 3879;a[366] = 3879;a[367] = 3879;a[368] = 1975;a[369] = 1975;a[370] = 1975;a[371] = 1975;a[372] = 1975;a[373] = 1975;a[374] = 1975;a[375] = 1975;a[376] = 3879;a[377] = 3879;
	a[378] = 3879;a[379] = 3879;a[380] = 3879;a[381] = 3879;a[382] = 3879;a[383] = 3879;a[384] = 1001;a[385] = 1001;a[386] = 1001;a[387] = 1001;a[388] = 1001;a[389] = 1001;a[390] = 1001;a[391] = 1001;a[392] = 5719;a[393] = 5719;a[394] = 5719;a[395] = 5719;
	a[396] = 5719;a[397] = 5719;a[398] = 5719;a[399] = 5719;a[400] = 1001;a[401] = 1001;a[402] = 1001;a[403] = 1001;a[404] = 1001;a[405] = 1001;a[406] = 1001;a[407] = 1001;a[408] = 5719;a[409] = 5719;a[410] = 5719;a[411] = 5719;a[412] = 5719;a[413] = 5719;a[414] = 5719;a[415] = 5719;a[416] = 1001;a[417] = 1001;a[418] = 1001;a[419] = 1001;a[420] = 1001;a[421] = 1001;a[422] = 1001;a[423] = 1001;a[424] = 5719;a[425] = 5719;a[426] = 5719;a[427] = 5719;a[428] = 5719;a[429] = 5719;a[430] = 5719;a[431] = 5719;a[432] = 1001;a[433] = 1001;a[434] = 1001;a[435] = 1001;a[436] = 1001;a[437] = 1001;a[438] = 1001;a[439] = 1001;a[440] = 5719;a[441] = 5719;a[442] = 5719;a[443] = 5719;a[444] = 5719;a[445] = 5719;a[446] = 5719;a[447] = 5719;a[448] = 47089;a[449] = 47089;a[450] = 47089;a[451] = 47089;a[452] = 47089;
	a[453] = 47089;a[454] = 47089;a[455] = 47089;a[456] = 47089;a[457] = 47089;a[458] = 47089;a[459] = 47089;a[460] = 47089;a[461] = 47089;a[462] = 47089;a[463] = 47089;a[464] = 47089;a[465] = 47089;a[466] = 47089;a[467] = 47089;a[468] = 47089;a[469] = 47089;a[470] = 47089;a[471] = 47089;a[472] = 47089;a[473] = 47089;a[474] = 47089;a[475] = 47089;a[476] = 47089;a[477] = 47089;a[478] = 47089;a[479] = 47089;a[480] = 48769;a[481] = 48769;
	a[482] = 48769;a[483] = 48769;a[484] = 48769;a[485] = 48769;a[486] = 48769;a[487] = 48769;a[488] = 58775;a[489] = 58775;a[490] = 58775;a[491] = 58775;a[492] = 58775;a[493] = 58775;a[494] = 58775;a[495] = 58775;a[496] = 48769;a[497] = 48769;a[498] = 48769;a[499] = 48769;a[500] = 48769;a[501] = 48769;a[502] = 48769;a[503] = 48769;a[504] = 58775;a[505] = 58775;a[506] = 58775;a[507] = 58775;a[508] = 58775;a[509] = 58775;a[510] = 58775;a[511] = 58775;a[512] = 3;a[513] = 3;a[514] = 3;a[515] = 3;a[516] = 3;a[517] = 3;a[518] = 3;a[519] = 3;a[520] = 3;a[521] = 3;a[522] = 3;a[523] = 3;a[524] = 3;a[525] = 3;a[526] = 3;a[527] = 3;a[528] = 3;a[529] = 3;a[530] = 3;a[531] = 3;a[532] = 3;a[533] = 3;a[534] = 3;a[535] = 3;a[536] = 3;a[537] = 3;a[538] = 3;a[539] = 3;a[540] = 3;a[541] = 3;
	a[542] = 3;a[543] = 3;a[544] = 27;a[545] = 27;a[546] = 27;a[547] = 27;a[548] = 27;a[549] = 27;a[550] = 27;a[551] = 27;a[552] = 27;a[553] = 27;a[554] = 27;a[555] = 27;a[556] = 27;a[557] = 27;
	a[558] = 27;a[559] = 27;a[560] = 27;a[561] = 27;a[562] = 27;a[563] = 27;a[564] = 27;a[565] = 27;a[566] = 27;a[567] = 27;a[568] = 27;a[569] = 27;a[570] = 27;a[571] = 27;a[572] = 27;
	a[573] = 27;a[574] = 27;a[575] = 27;a[576] = 415;a[577] = 415;a[578] = 415;a[579] = 415;a[580] = 415;a[581] = 415;a[582] = 415;a[583] = 415;a[584] = 707;a[585] = 707;a[586] = 707;a[587] = 707;a[588] = 707;a[589] = 707;a[590] = 707;
	a[591] = 707;a[592] = 415;a[593] = 415;
	a[594] = 415;a[595] = 415;a[596] = 415;a[597] = 415;a[598] = 415;a[599] = 415;a[600] = 707;a[601] = 707;a[602] = 707;a[603] = 707;a[604] = 707;a[605] = 707;a[606] = 707;a[607] = 707;a[608] = 415;a[609] = 415;a[610] = 415;a[611] = 415;a[612] = 415;a[613] = 415;a[614] = 415;a[615] = 415;a[616] = 1695;a[617] = 1695;a[618] = 1695;a[619] = 1695;a[620] = 1695;a[621] = 1695;a[622] = 1695;a[623] = 1695;a[624] = 415;a[625] = 415;a[626] = 415;a[627] = 415;a[628] = 415;a[629] = 415;a[630] = 415;a[631] = 415;a[632] = 1695;a[633] = 1695;a[634] = 1695;a[635] = 1695;a[636] = 1695;a[637] = 1695;a[638] = 1695;a[639] = 1695;a[640] = 125;a[641] = 125;a[642] = 125;a[643] = 125;a[644] = 125;a[645] = 125;a[646] = 125;a[647] = 125;a[648] = 143;a[649] = 143;a[650] = 143;a[651] = 143;a[652] = 143;a[653] = 143;a[654] = 143;a[655] = 143;a[656] = 125;a[657] = 125;a[658] = 125;a[659] = 125;a[660] = 125;a[661] = 125;a[662] = 125;a[663] = 125;a[664] = 143;a[665] = 143;a[666] = 143;a[667] = 143;a[668] = 143;a[669] = 143;
	a[670] = 143;a[671] = 143;a[672] = 125;a[673] = 125;a[674] = 125;a[675] = 125;a[676] = 125;a[677] = 125;a[678] = 125;a[679] = 125;a[680] = 143;a[681] = 143;a[682] = 143;a[683] = 143;a[684] = 143;a[685] = 143;a[686] = 143;a[687] = 143;a[688] = 125;a[689] = 125;a[690] = 125;a[691] = 125;a[692] = 125;a[693] = 125;a[694] = 125;a[695] = 125;a[696] = 143;a[697] = 143;a[698] = 143;a[699] = 143;a[700] = 143;a[701] = 143;a[702] = 143;a[703] = 143;a[704] = 2753;a[705] = 2753;a[706] = 2753;a[707] = 2753;a[708] = 2753;a[709] = 2753;a[710] = 2753;a[711] = 2753;a[712] = 37131;a[713] = 37131;a[714] = 37131;a[715] = 37131;a[716] = 37131;a[717] = 37131;a[718] = 37131;a[719] = 37131;a[720] = 2753;a[721] = 2753;a[722] = 2753;a[723] = 2753;a[724] = 2753;a[725] = 2753;a[726] = 2753;a[727] = 2753;a[728] = 37131;
	a[729] = 37131;a[730] = 37131;a[731] = 37131;a[732] = 37131;a[733] = 37131;a[734] = 37131;a[735] = 37131;a[736] = 37131;a[737] = 37131;a[738] = 37131;a[739] = 37131;a[740] = 37131;a[741] = 37131;a[742] = 37131;a[743] = 37131;a[744] = 37131;a[745] = 37131;a[746] = 37131;a[747] = 37131;a[748] = 37131;a[749] = 37131;a[750] = 37131;a[751] = 37131;a[752] = 37131;a[753] = 37131;a[754] = 37131;a[755] = 37131;a[756] = 37131;a[757] = 37131;a[758] = 37131;a[759] = 37131;a[760] = 37131;a[761] = 37131;a[762] = 37131;a[763] = 37131;a[764] = 37131;
	a[765] = 37131;a[766] = 37131;a[767] = 37131;a[768] = 27;a[769] = 27;a[770] = 27;a[771] = 27;a[772] = 27;a[773] = 27;a[774] = 27;a[775] = 27;a[776] = 27;a[777] = 27;a[778] = 27;a[779] = 27;a[780] = 27;a[781] = 27;a[782] = 27;a[783] = 27;a[784] = 27;a[785] = 27;a[786] = 27;a[787] = 27;a[788] = 27;a[789] = 27;a[790] = 27;a[791] = 27;a[792] = 27;a[793] = 27;a[794] = 27;a[795] = 27;a[796] = 27;a[797] = 27;a[798] = 27;a[799] = 27;
	a[800] = 27;a[801] = 27;a[802] = 27;a[803] = 27;a[804] = 27;a[805] = 27;a[806] = 27;a[807] = 27;a[808] = 27;a[809] = 27;a[810] = 27;a[811] = 27;a[812] = 27;a[813] = 27;a[814] = 27;a[815] = 27;a[816] = 27;a[817] = 27;a[818] = 27;a[819] = 27;a[820] = 27;a[821] = 27;a[822] = 27;a[823] = 27;a[824] = 27;a[825] = 27;a[826] = 27;a[827] = 27;a[828] = 27;a[829] = 27;a[830] = 27;a[831] = 27;a[832] = 4977;a[833] = 4977;a[834] = 4977;a[835] = 4977;a[836] = 4977;a[837] = 4977;a[838] = 4977;a[839] = 4977;a[840] = 10089;a[841] = 10089;a[842] = 10089;a[843] = 10089;a[844] = 10089;a[845] = 10089;a[846] = 10089;a[847] = 10089;a[848] = 4977;a[849] = 4977;a[850] = 4977;a[851] = 4977;a[852] = 4977;a[853] = 4977;a[854] = 4977;a[855] = 4977;a[856] = 10089;a[857] = 10089;a[858] = 10089;a[859] = 10089;a[860] = 10089;a[861] = 10089;a[862] = 10089;a[863] = 10089;a[864] = 4977;a[865] = 4977;a[866] = 4977;a[867] = 4977;a[868] = 4977;a[869] = 4977;a[870] = 4977;a[871] = 4977;a[872] = 23117;a[873] = 23117;a[874] = 23117;a[875] = 23117;a[876] = 23117;a[877] = 23117;a[878] = 23117;a[879] = 23117;a[880] = 4977;a[881] = 4977;a[882] = 4977;a[883] = 4977;a[884] = 4977;a[885] = 4977;a[886] = 4977;a[887] = 4977;a[888] = 23117;a[889] = 23117;a[890] = 23117;a[891] = 23117;a[892] = 23117;a[893] = 23117;a[894] = 23117;a[895] = 23117;a[896] = 6393;a[897] = 6393;a[898] = 6393;a[899] = 6393;a[900] = 6393;a[901] = 6393;a[902] = 6393;a[903] = 6393;a[904] = 35785;a[905] = 35785;a[906] = 35785;a[907] = 35785;a[908] = 35785;a[909] = 35785;a[910] = 35785;a[911] = 35785;a[912] = 6393;a[913] = 6393;a[914] = 6393;a[915] = 6393;a[916] = 6393;
	a[917] = 6393;a[918] = 6393;a[919] = 6393;a[920] = 35785;a[921] = 35785;a[922] = 35785;a[923] = 35785;a[924] = 35785;a[925] = 35785;a[926] = 35785;a[927] = 35785;a[928] = 6393;a[929] = 6393;a[930] = 6393;a[931] = 6393;a[932] = 6393;a[933] = 6393;a[934] = 6393;a[935] = 6393;a[936] = 128821;a[937] = 128821;
	a[938] = 128821;a[939] = 128821;a[940] = 128821;a[941] = 128821;a[942] = 128821;a[943] = 128821;a[944] = 6393;a[945] = 6393;a[946] = 6393;a[947] = 6393;a[948] = 6393;a[949] = 6393;a[950] = 6393;a[951] = 6393;a[952] = 128821;a[953] = 128821;a[954] = 128821;a[955] = 128821;a[956] = 128821;a[957] = 128821;a[958] = 128821;a[959] = 128821;a[960] = 569669;a[961] = 569669;a[962] = 569669;a[963] = 569669;a[964] = 569669;a[965] = 569669;a[966] = 569669;a[967] = 569669;
	a[968] = 569669;a[969] = 569669;a[970] = 569669;a[971] = 569669;a[972] = 569669;a[973] = 569669;a[974] = 569669;a[975] = 569669;a[976] = 569669;a[977] = 569669;a[978] = 569669;a[979] = 569669;a[980] = 569669;a[981] = 569669;a[982] = 569669;a[983] = 569669;a[984] = 569669;a[985] = 569669;a[986] = 569669;a[987] = 569669;a[988] = 569669;a[989] = 569669;a[990] = 569669;a[991] = 569669;a[992] = 569669;a[993] = 569669;a[994] = 569669;a[995] = 569669;a[996] = 569669;a[997] = 569669;a[998] = 569669;a[999] = 569669;a[1000] = 569669;a[1001] = 569669;a[1002] = 569669;a[1003] = 569669;a[1004] = 569669;a[1005] = 569669;a[1006] = 569669;a[1007] = 569669;a[1008] = 569669;a[1009] = 569669;a[1010] = 569669;a[1011] = 569669;a[1012] = 569669;a[1013] = 569669;a[1014] = 569669;a[1015] = 569669;a[1016] = 569669;a[1017] = 569669;a[1018] = 569669;a[1019] = 569669;a[1020] = 569669;a[1021] = 569669;a[1022] = 569669;a[1023] = 569669;a[1024] = 7;a[1025] = 7;a[1026] = 7;a[1027] = 7;a[1028] = 7;a[1029] = 7;a[1030] = 7;a[1031] = 7;a[1032] = 13;a[1033] = 13;a[1034] = 13;a[1035] = 13;a[1036] = 13;a[1037] = 13;a[1038] = 13;a[1039] = 13;a[1040] = 7;a[1041] = 7;a[1042] = 7;a[1043] = 7;a[1044] = 7;a[1045] = 7;a[1046] = 7;a[1047] = 7;a[1048] = 13;a[1049] = 13;a[1050] = 13;a[1051] = 13;
	a[1052] = 13;a[1053] = 13;a[1054] = 13;a[1055] = 13;a[1056] = 7;a[1057] = 7;a[1058] = 7;a[1059] = 7;a[1060] = 7;a[1061] = 7;a[1062] = 7;a[1063] = 7;a[1064] = 23;a[1065] = 23;a[1066] = 23;a[1067] = 23;
	a[1068] = 23;a[1069] = 23;a[1070] = 23;a[1071] = 23;a[1072] = 7;a[1073] = 7;a[1074] = 7;a[1075] = 7;a[1076] = 7;a[1077] = 7;a[1078] = 7;a[1079] = 7;a[1080] = 23;a[1081] = 23;a[1082] = 23;a[1083] = 23;a[1084] = 23;a[1085] = 23;a[1086] = 23;a[1087] = 23;a[1088] = 44;a[1089] = 44;a[1090] = 44;a[1091] = 44;a[1092] = 44;a[1093] = 44;a[1094] = 44;a[1095] = 44;a[1096] = 79;a[1097] = 79;a[1098] = 79;a[1099] = 79;a[1100] = 79;a[1101] = 79;a[1102] = 79;a[1103] = 79;a[1104] = 44;a[1105] = 44;a[1106] = 44;a[1107] = 44;a[1108] = 44;a[1109] = 44;a[1110] = 44;a[1111] = 44;a[1112] = 79;a[1113] = 79;a[1114] = 79;a[1115] = 79;a[1116] = 79;a[1117] = 79;a[1118] = 79;a[1119] = 79;a[1120] = 49;a[1121] = 49;a[1122] = 49;a[1123] = 49;a[1124] = 49;a[1125] = 49;a[1126] = 49;a[1127] = 49;a[1128] = 79;a[1129] = 79;a[1130] = 79;a[1131] = 79;a[1132] = 79;a[1133] = 79;a[1134] = 79;a[1135] = 79;a[1136] = 49;a[1137] = 49;a[1138] = 49;a[1139] = 49;a[1140] = 49;a[1141] = 49;a[1142] = 49;a[1143] = 49;a[1144] = 79;a[1145] = 79;a[1146] = 79;a[1147] = 79;a[1148] = 79;a[1149] = 79;a[1150] = 79;a[1151] = 79;a[1152] = 7;a[1153] = 7;a[1154] = 7;a[1155] = 7;a[1156] = 7;a[1157] = 7;a[1158] = 7;a[1159] = 7;a[1160] = 167;a[1161] = 167;a[1162] = 167;a[1163] = 167;a[1164] = 167;a[1165] = 167;a[1166] = 167;a[1167] = 167;a[1168] = 7;a[1169] = 7;a[1170] = 7;a[1171] = 7;a[1172] = 7;a[1173] = 7;a[1174] = 7;a[1175] = 7;a[1176] = 167;a[1177] = 167;a[1178] = 167;a[1179] = 167;a[1180] = 167;a[1181] = 167;a[1182] = 167;a[1183] = 167;
	a[1184] = 7;a[1185] = 7;a[1186] = 7;a[1187] = 7;a[1188] = 7;a[1189] = 7;a[1190] = 7;a[1191] = 7;a[1192] = 7895;a[1193] = 7895;a[1194] = 7895;a[1195] = 7895;a[1196] = 7895;a[1197] = 7895;a[1198] = 7895;a[1199] = 7895;a[1200] = 7;a[1201] = 7;a[1202] = 7;a[1203] = 7;a[1204] = 7;a[1205] = 7;a[1206] = 7;a[1207] = 7;a[1208] = 7895;a[1209] = 7895;a[1210] = 7895;a[1211] = 7895;a[1212] = 7895;a[1213] = 7895;a[1214] = 7895;a[1215] = 7895;a[1216] = 49;a[1217] = 49;a[1218] = 49;a[1219] = 49;a[1220] = 49;a[1221] = 49;a[1222] = 49;a[1223] = 49;a[1224] = 6307;a[1225] = 6307;a[1226] = 6307;a[1227] = 6307;a[1228] = 6307;a[1229] = 6307;a[1230] = 6307;a[1231] = 6307;a[1232] = 49;a[1233] = 49;a[1234] = 49;a[1235] = 49;a[1236] = 49;a[1237] = 49;a[1238] = 49;a[1239] = 49;a[1240] = 6307;a[1241] = 6307;a[1242] = 6307;a[1243] = 6307;a[1244] = 6307;a[1245] = 6307;a[1246] = 6307;a[1247] = 6307;a[1248] = 49;a[1249] = 49;a[1250] = 49;a[1251] = 49;a[1252] = 49;a[1253] = 49;a[1254] = 49;a[1255] = 49;a[1256] = 7895;a[1257] = 7895;a[1258] = 7895;a[1259] = 7895;a[1260] = 7895;a[1261] = 7895;a[1262] = 7895;a[1263] = 7895;a[1264] = 49;a[1265] = 49;a[1266] = 49;a[1267] = 49;a[1268] = 49;a[1269] = 49;a[1270] = 49;a[1271] = 49;a[1272] = 7895;a[1273] = 7895;a[1274] = 7895;a[1275] = 7895;a[1276] = 7895;a[1277] = 7895;a[1278] = 7895;a[1279] = 7895;a[1280] = 97;a[1281] = 97;a[1282] = 97;a[1283] = 97;a[1284] = 97;a[1285] = 97;a[1286] = 97;a[1287] = 97;a[1288] = 219;a[1289] = 219;a[1290] = 219;a[1291] = 219;a[1292] = 219;a[1293] = 219;a[1294] = 219;a[1295] = 219;a[1296] = 97;a[1297] = 97;a[1298] = 97;a[1299] = 97;
	a[1300] = 97;a[1301] = 97;a[1302] = 97;a[1303] = 97;a[1304] = 219;a[1305] = 219;a[1306] = 219;a[1307] = 219;a[1308] = 219;a[1309] = 219;a[1310] = 219;a[1311] = 219;a[1312] = 219;a[1313] = 219;a[1314] = 219;a[1315] = 219;a[1316] = 219;a[1317] = 219;a[1318] = 219;a[1319] = 219;a[1320] = 219;a[1321] = 219;a[1322] = 219;a[1323] = 219;a[1324] = 219;a[1325] = 219;a[1326] = 219;a[1327] = 219;a[1328] = 219;a[1329] = 219;a[1330] = 219;a[1331] = 219;a[1332] = 219;a[1333] = 219;a[1334] = 219;
	a[1335] = 219;a[1336] = 219;a[1337] = 219;a[1338] = 219;a[1339] = 219;a[1340] = 219;a[1341] = 219;a[1342] = 219;a[1343] = 219;a[1344] = 608;a[1345] = 608;a[1346] = 608;a[1347] = 608;a[1348] = 608;a[1349] = 608;a[1350] = 608;a[1351] = 608;a[1352] = 3879;a[1353] = 3879;a[1354] = 3879;
	a[1355] = 3879;a[1356] = 3879;a[1357] = 3879;a[1358] = 3879;a[1359] = 3879;a[1360] = 608;a[1361] = 608;a[1362] = 608;a[1363] = 608;a[1364] = 608;a[1365] = 608;a[1366] = 608;a[1367] = 608;a[1368] = 3879;
	a[1369] = 3879;a[1370] = 3879;a[1371] = 3879;a[1372] = 3879;a[1373] = 3879;a[1374] = 3879;a[1375] = 3879;a[1376] = 3879;a[1377] = 3879;a[1378] = 3879;a[1379] = 3879;a[1380] = 3879;a[1381] = 3879;a[1382] = 3879;a[1383] = 3879;a[1384] = 3879;a[1385] = 3879;a[1386] = 3879;a[1387] = 3879;a[1388] = 3879;a[1389] = 3879;a[1390] = 3879;a[1391] = 3879;a[1392] = 3879;a[1393] = 3879;a[1394] = 3879;a[1395] = 3879;a[1396] = 3879;a[1397] = 3879;a[1398] = 3879;a[1399] = 3879;a[1400] = 3879;a[1401] = 3879;a[1402] = 3879;a[1403] = 3879;a[1404] = 3879;a[1405] = 3879;a[1406] = 3879;a[1407] = 3879;a[1408] = 34527;a[1409] = 34527;a[1410] = 34527;a[1411] = 34527;a[1412] = 34527;a[1413] = 34527;a[1414] = 34527;a[1415] = 34527;a[1416] = 48041;a[1417] = 48041;a[1418] = 48041;a[1419] = 48041;a[1420] = 48041;a[1421] = 48041;a[1422] = 48041;a[1423] = 48041;a[1424] = 34527;a[1425] = 34527;a[1426] = 34527;a[1427] = 34527;a[1428] = 34527;a[1429] = 34527;a[1430] = 34527;a[1431] = 34527;a[1432] = 48041;a[1433] = 48041;a[1434] = 48041;a[1435] = 48041;a[1436] = 48041;a[1437] = 48041;a[1438] = 48041;a[1439] = 48041;a[1440] = 34527;a[1441] = 34527;a[1442] = 34527;a[1443] = 34527;a[1444] = 34527;a[1445] = 34527;a[1446] = 34527;a[1447] = 34527;a[1448] = 120407;a[1449] = 120407;a[1450] = 120407;a[1451] = 120407;a[1452] = 120407;a[1453] = 120407;a[1454] = 120407;a[1455] = 120407;a[1456] = 34527;a[1457] = 34527;a[1458] = 34527;a[1459] = 34527;a[1460] = 34527;a[1461] = 34527;a[1462] = 34527;a[1463] = 34527;a[1464] = 120407;a[1465] = 120407;a[1466] = 120407;a[1467] = 120407;a[1468] = 120407;a[1469] = 120407;a[1470] = 120407;a[1471] = 120407;a[1472] = 245035;a[1473] = 245035;a[1474] = 245035;a[1475] = 245035;a[1476] = 245035;a[1477] = 245035;a[1478] = 245035;a[1479] = 245035;a[1480] = 697563;a[1481] = 697563;a[1482] = 697563;a[1483] = 697563;a[1484] = 697563;a[1485] = 697563;a[1486] = 697563;a[1487] = 697563;a[1488] = 245035;a[1489] = 245035;a[1490] = 245035;a[1491] = 245035;a[1492] = 245035;a[1493] = 245035;a[1494] = 245035;a[1495] = 245035;a[1496] = 697563;a[1497] = 697563;a[1498] = 697563;a[1499] = 697563;a[1500] = 697563;a[1501] = 697563;a[1502] = 697563;a[1503] = 697563;a[1504] = 245035;a[1505] = 245035;a[1506] = 245035;a[1507] = 245035;a[1508] = 245035;a[1509] = 245035;a[1510] = 245035;a[1511] = 245035;a[1512] = 2688153;a[1513] = 2688153;a[1514] = 2688153;a[1515] = 2688153;a[1516] = 2688153;a[1517] = 2688153;a[1518] = 2688153;a[1519] = 2688153;a[1520] = 245035;a[1521] = 245035;a[1522] = 245035;a[1523] = 245035;a[1524] = 245035;a[1525] = 245035;a[1526] = 245035;a[1527] = 245035;a[1528] = 2688153;a[1529] = 2688153;a[1530] = 2688153;a[1531] = 2688153;a[1532] = 2688153;a[1533] = 2688153;a[1534] = 2688153;a[1535] = 2688153;a[1536] = 91;a[1537] = 91;a[1538] = 91;a[1539] = 91;a[1540] = 91;a[1541] = 91;a[1542] = 91;a[1543] = 91;a[1544] = 91;a[1545] = 91;a[1546] = 91;a[1547] = 91;a[1548] = 91;a[1549] = 91;a[1550] = 91;a[1551] = 91;a[1552] = 91;a[1553] = 91;a[1554] = 91;a[1555] = 91;a[1556] = 91;a[1557] = 91;a[1558] = 91;a[1559] = 91;a[1560] = 91;a[1561] = 91;a[1562] = 91;a[1563] = 91;a[1564] = 91;a[1565] = 91;a[1566] = 91;a[1567] = 91;a[1568] = 91;a[1569] = 91;a[1570] = 91;a[1571] = 91;a[1572] = 91;a[1573] = 91;a[1574] = 91;a[1575] = 91;a[1576] = 91;a[1577] = 91;a[1578] = 91;a[1579] = 91;a[1580] = 91;a[1581] = 91;a[1582] = 91;a[1583] = 91;a[1584] = 91;a[1585] = 91;a[1586] = 91;a[1587] = 91;a[1588] = 91;a[1589] = 91;a[1590] = 91;a[1591] = 91;a[1592] = 91;a[1593] = 91;a[1594] = 91;a[1595] = 91;a[1596] = 91;a[1597] = 91;a[1598] = 91;a[1599] = 91;a[1600] = 1033;a[1601] = 1033;a[1602] = 1033;a[1603] = 1033;a[1604] = 1033;a[1605] = 1033;a[1606] = 1033;a[1607] = 1033;a[1608] = 6073;a[1609] = 6073;a[1610] = 6073;a[1611] = 6073;a[1612] = 6073;a[1613] = 6073;a[1614] = 6073;a[1615] = 6073;a[1616] = 1033;a[1617] = 1033;a[1618] = 1033;a[1619] = 1033;a[1620] = 1033;a[1621] = 1033;a[1622] = 1033;a[1623] = 1033;a[1624] = 6073;a[1625] = 6073;a[1626] = 6073;a[1627] = 6073;a[1628] = 6073;a[1629] = 6073;a[1630] = 6073;a[1631] = 6073;a[1632] = 4577;a[1633] = 4577;a[1634] = 4577;a[1635] = 4577;a[1636] = 4577;a[1637] = 4577;a[1638] = 4577;a[1639] = 4577;a[1640] = 6073;a[1641] = 6073;a[1642] = 6073;a[1643] = 6073;a[1644] = 6073;a[1645] = 6073;a[1646] = 6073;a[1647] = 6073;a[1648] = 4577;a[1649] = 4577;a[1650] = 4577;a[1651] = 4577;a[1652] = 4577;a[1653] = 4577;a[1654] = 4577;a[1655] = 4577;a[1656] = 6073;a[1657] = 6073;a[1658] = 6073;a[1659] = 6073;a[1660] = 6073;a[1661] = 6073;a[1662] = 6073;a[1663] = 6073;a[1664] = 1337;a[1665] = 1337;a[1666] = 1337;a[1667] = 1337;a[1668] = 1337;a[1669] = 1337;a[1670] = 1337;a[1671] = 1337;a[1672] = 1337;a[1673] = 1337;a[1674] = 1337;a[1675] = 1337;a[1676] = 1337;a[1677] = 1337;a[1678] = 1337;a[1679] = 1337;a[1680] = 1337;a[1681] = 1337;a[1682] = 1337;a[1683] = 1337;a[1684] = 1337;a[1685] = 1337;a[1686] = 1337;a[1687] = 1337;a[1688] = 1337;a[1689] = 1337;a[1690] = 1337;a[1691] = 1337;a[1692] = 1337;a[1693] = 1337;a[1694] = 1337;a[1695] = 1337;a[1696] = 29913;a[1697] = 29913;a[1698] = 29913;a[1699] = 29913;a[1700] = 29913;a[1701] = 29913;a[1702] = 29913;a[1703] = 29913;a[1704] = 120149;a[1705] = 120149;a[1706] = 120149;a[1707] = 120149;a[1708] = 120149;a[1709] = 120149;a[1710] = 120149;a[1711] = 120149;a[1712] = 29913;a[1713] = 29913;a[1714] = 29913;a[1715] = 29913;a[1716] = 29913;a[1717] = 29913;a[1718] = 29913;a[1719] = 29913;a[1720] = 120149;a[1721] = 120149;a[1722] = 120149;a[1723] = 120149;a[1724] = 120149;a[1725] = 120149;a[1726] = 120149;a[1727] = 120149;a[1728] = 71735;
	a[1729] = 71735;a[1730] = 71735;a[1731] = 71735;a[1732] = 71735;a[1733] = 71735;a[1734] = 71735;a[1735] = 71735;a[1736] = 613479;a[1737] = 613479;a[1738] = 613479;a[1739] = 613479;a[1740] = 613479;a[1741] = 613479;a[1742] = 613479;a[1743] = 613479;a[1744] = 71735;a[1745] = 71735;a[1746] = 71735;a[1747] = 71735;a[1748] = 71735;a[1749] = 71735;a[1750] = 71735;a[1751] = 71735;a[1752] = 613479;a[1753] = 613479;a[1754] = 613479;a[1755] = 613479;a[1756] = 613479;a[1757] = 613479;a[1758] = 613479;a[1759] = 613479;a[1760] = 218301;a[1761] = 218301;a[1762] = 218301;a[1763] = 218301;a[1764] = 218301;a[1765] = 218301;a[1766] = 218301;a[1767] = 218301;a[1768] = 711725;a[1769] = 711725;a[1770] = 711725;a[1771] = 711725;a[1772] = 711725;a[1773] = 711725;a[1774] = 711725;a[1775] = 711725;a[1776] = 218301;a[1777] = 218301;a[1778] = 218301;a[1779] = 218301;a[1780] = 218301;a[1781] = 218301;a[1782] = 218301;a[1783] = 218301;a[1784] = 711725;a[1785] = 711725;a[1786] = 711725;a[1787] = 711725;a[1788] = 711725;a[1789] = 711725;a[1790] = 711725;a[1791] = 711725;a[1792] = 1177;a[1793] = 1177;a[1794] = 1177;a[1795] = 1177;a[1796] = 1177;a[1797] = 1177;a[1798] = 1177;a[1799] = 1177;a[1800] = 1177;a[1801] = 1177;a[1802] = 1177;a[1803] = 1177;a[1804] = 1177;a[1805] = 1177;a[1806] = 1177;a[1807] = 1177;a[1808] = 1177;a[1809] = 1177;a[1810] = 1177;a[1811] = 1177;a[1812] = 1177;a[1813] = 1177;a[1814] = 1177;a[1815] = 1177;a[1816] = 1177;a[1817] = 1177;a[1818] = 1177;a[1819] = 1177;a[1820] = 1177;a[1821] = 1177;a[1822] = 1177;a[1823] = 1177;a[1824] = 1177;a[1825] = 1177;a[1826] = 1177;a[1827] = 1177;a[1828] = 1177;a[1829] = 1177;a[1830] = 1177;a[1831] = 1177;a[1832] = 1177;a[1833] = 1177;a[1834] = 1177;a[1835] = 1177;a[1836] = 1177;a[1837] = 1177;a[1838] = 1177;a[1839] = 1177;a[1840] = 1177;a[1841] = 1177;a[1842] = 1177;a[1843] = 1177;a[1844] = 1177;a[1845] = 1177;a[1846] = 1177;a[1847] = 1177;a[1848] = 1177;a[1849] = 1177;a[1850] = 1177;a[1851] = 1177;a[1852] = 1177;a[1853] = 1177;a[1854] = 1177;a[1855] = 1177;a[1856] = 9867;a[1857] = 9867;a[1858] = 9867;a[1859] = 9867;a[1860] = 9867;a[1861] = 9867;a[1862] = 9867;a[1863] = 9867;a[1864] = 28099;a[1865] = 28099;a[1866] = 28099;a[1867] = 28099;a[1868] = 28099;a[1869] = 28099;a[1870] = 28099;a[1871] = 28099;a[1872] = 9867;a[1873] = 9867;a[1874] = 9867;a[1875] = 9867;a[1876] = 9867;a[1877] = 9867;a[1878] = 9867;a[1879] = 9867;a[1880] = 28099;a[1881] = 28099;a[1882] = 28099;a[1883] = 28099;a[1884] = 28099;a[1885] = 28099;a[1886] = 28099;a[1887] = 28099;a[1888] = 28099;a[1889] = 28099;a[1890] = 28099;a[1891] = 28099;a[1892] = 28099;a[1893] = 28099;a[1894] = 28099;a[1895] = 28099;a[1896] = 28099;a[1897] = 28099;a[1898] = 28099;a[1899] = 28099;a[1900] = 28099;a[1901] = 28099;a[1902] = 28099;a[1903] = 28099;a[1904] = 28099;a[1905] = 28099;a[1906] = 28099;a[1907] = 28099;a[1908] = 28099;a[1909] = 28099;a[1910] = 28099;a[1911] = 28099;a[1912] = 28099;a[1913] = 28099;a[1914] = 28099;a[1915] = 28099;a[1916] = 28099;a[1917] = 28099;a[1918] = 28099;a[1919] = 28099;a[1920] = 48041;a[1921] = 48041;a[1922] = 48041;a[1923] = 48041;a[1924] = 48041;a[1925] = 48041;a[1926] = 48041;a[1927] = 48041;a[1928] = 48041;a[1929] = 48041;a[1930] = 48041;a[1931] = 48041;a[1932] = 48041;a[1933] = 48041;a[1934] = 48041;a[1935] = 48041;a[1936] = 48041;a[1937] = 48041;a[1938] = 48041;a[1939] = 48041;a[1940] = 48041;a[1941] = 48041;a[1942] = 48041;a[1943] = 48041;a[1944] = 48041;a[1945] = 48041;a[1946] = 48041;a[1947] = 48041;a[1948] = 48041;a[1949] = 48041;a[1950] = 48041;a[1951] = 48041;a[1952] = 246297;a[1953] = 246297;a[1954] = 246297;a[1955] = 246297;a[1956] = 246297;a[1957] = 246297;a[1958] = 246297;a[1959] = 246297;a[1960] = 346719;a[1961] = 346719;a[1962] = 346719;a[1963] = 346719;a[1964] = 346719;a[1965] = 346719;a[1966] = 346719;a[1967] = 346719;a[1968] = 246297;a[1969] = 246297;a[1970] = 246297;a[1971] = 246297;a[1972] = 246297;a[1973] = 246297;a[1974] = 246297;a[1975] = 246297;a[1976] = 346719;a[1977] = 346719;a[1978] = 346719;a[1979] = 346719;a[1980] = 346719;a[1981] = 346719;a[1982] = 346719;a[1983] = 346719;a[1984] = 2662657;a[1985] = 2662657;a[1986] = 2662657;a[1987] = 2662657;a[1988] = 2662657;a[1989] = 2662657;a[1990] = 2662657;a[1991] = 2662657;a[1992] = 4817803;a[1993] = 4817803;a[1994] = 4817803;a[1995] = 4817803;a[1996] = 4817803;a[1997] = 4817803;a[1998] = 4817803;a[1999] = 4817803;a[2000] = 2662657;a[2001] = 2662657;a[2002] = 2662657;a[2003] = 2662657;a[2004] = 2662657;a[2005] = 2662657;a[2006] = 2662657;a[2007] = 2662657;a[2008] = 4817803;a[2009] = 4817803;a[2010] = 4817803;a[2011] = 4817803;a[2012] = 4817803;a[2013] = 4817803;a[2014] = 4817803;a[2015] = 4817803;a[2016] = 11814485;a[2017] = 11814485;a[2018] = 11814485;a[2019] = 11814485;a[2020] = 11814485;a[2021] = 11814485;a[2022] = 11814485;a[2023] = 11814485;a[2024] = 11814485;a[2025] = 11814485;a[2026] = 11814485;a[2027] = 11814485;a[2028] = 11814485;a[2029] = 11814485;a[2030] = 11814485;a[2031] = 11814485;a[2032] = 11814485;a[2033] = 11814485;a[2034] = 11814485;a[2035] = 11814485;a[2036] = 11814485;a[2037] = 11814485;a[2038] = 11814485;a[2039] = 11814485;a[2040] = 11814485;a[2041] = 11814485;a[2042] = 11814485;a[2043] = 11814485;a[2044] = 11814485;a[2045] = 11814485;a[2046] = 11814485;a[2047] = 11814485;
	int T;
	getn(&T);
	for(int ca = 1; ca <= T; ca++)
	{
		int mp = 0;
		int base;
		while(true){
			bool flag = getn(&base);
			mp |= (1 << base);
			if(!flag){
				break;
			}
		}
		printf("Case #%d: %d\n", ca, a[mp]);
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
}