#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/OpenGL.hpp>
#include <map>
#include <iostream>
#include <cassert>
#include <vector>
#include "StateMachine.h"
#include "AssetManager.h"
#include "State.h"
#include "Game.h"
#include "Definations.h"
using namespace std;
using namespace sf;
namespace rotf {
	class DarkSaber {
	public:
		DarkSaber(GameDataRef data): data(data) {};
		void init() {
			

			//walk

			//loading
			this->data->textures.load("dswalk01", dswalk001);
			this->data->textures.load("dswalk02", dswalk002);
			this->data->textures.load("dswalk03", dswalk003);
			this->data->textures.load("dswalk04", dswalk004);
			this->data->textures.load("dswalk05", dswalk005);
			this->data->textures.load("dswalk06", dswalk006);
			this->data->textures.load("dswalk07", dswalk007);
			this->data->textures.load("dswalk08", dswalk008);
			this->data->textures.load("dswalk09", dswalk009);
			this->data->textures.load("dswalk10", dswalk010);
			this->data->textures.load("dswalk11", dswalk011);
			this->data->textures.load("dswalk12", dswalk012);
			this->data->textures.load("dswalk13", dswalk013);
			this->data->textures.load("dswalk14", dswalk014);
			this->data->textures.load("dswalk15", dswalk015);
			this->data->textures.load("dswalk16", dswalk016);
			this->data->textures.load("dswalk17", dswalk017);
			this->data->textures.load("dswalk18", dswalk018);
			this->data->textures.load("dswalk19", dswalk019);
			this->data->textures.load("dswalk20", dswalk020);
			this->data->textures.load("dswalk21", dswalk021);
			this->data->textures.load("dswalk22", dswalk022);
			this->data->textures.load("dswalk23", dswalk023);
			this->data->textures.load("dswalk24", dswalk024);
			this->data->textures.load("dswalk25", dswalk025);
			this->data->textures.load("dswalk26", dswalk026);
			this->data->textures.load("dswalk27", dswalk027);
			this->data->textures.load("dswalk28", dswalk028);
			this->data->textures.load("dswalk29", dswalk029);
			this->data->textures.load("dswalk30", dswalk030);
			this->data->textures.load("dswalk31", dswalk031);
			this->data->textures.load("dswalk32", dswalk032);
			this->data->textures.load("dswalk33", dswalk033);
			this->data->textures.load("dswalk34", dswalk034);
			this->data->textures.load("dswalk35", dswalk035);
			this->data->textures.load("dswalk36", dswalk036);
			this->data->textures.load("dswalk37", dswalk037);
			this->data->textures.load("dswalk38", dswalk038);
			this->data->textures.load("dswalk39", dswalk039);


			//getting 
			this->dswalk[0].setTexture(this->data->textures.get("dswalk01"));
			this->dswalk[1].setTexture(this->data->textures.get("dswalk02"));
			this->dswalk[2].setTexture(this->data->textures.get("dswalk03"));
			this->dswalk[3].setTexture(this->data->textures.get("dswalk04"));
			this->dswalk[4].setTexture(this->data->textures.get("dswalk05"));
			this->dswalk[5].setTexture(this->data->textures.get("dswalk06"));
			this->dswalk[6].setTexture(this->data->textures.get("dswalk07"));
			this->dswalk[7].setTexture(this->data->textures.get("dswalk08"));
			this->dswalk[8].setTexture(this->data->textures.get("dswalk09"));
			this->dswalk[9].setTexture(this->data->textures.get("dswalk10"));
			this->dswalk[10].setTexture(this->data->textures.get("dswalk11"));
			this->dswalk[11].setTexture(this->data->textures.get("dswalk12"));
			this->dswalk[12].setTexture(this->data->textures.get("dswalk13"));
			this->dswalk[13].setTexture(this->data->textures.get("dswalk14"));
			this->dswalk[14].setTexture(this->data->textures.get("dswalk15"));
			this->dswalk[15].setTexture(this->data->textures.get("dswalk16"));
			this->dswalk[16].setTexture(this->data->textures.get("dswalk17"));
			this->dswalk[17].setTexture(this->data->textures.get("dswalk18"));
			this->dswalk[18].setTexture(this->data->textures.get("dswalk19"));
			this->dswalk[19].setTexture(this->data->textures.get("dswalk20"));
			this->dswalk[20].setTexture(this->data->textures.get("dswalk21"));
			this->dswalk[21].setTexture(this->data->textures.get("dswalk22"));
			this->dswalk[22].setTexture(this->data->textures.get("dswalk23"));
			this->dswalk[23].setTexture(this->data->textures.get("dswalk24"));
			this->dswalk[24].setTexture(this->data->textures.get("dswalk25"));
			this->dswalk[25].setTexture(this->data->textures.get("dswalk26"));
			this->dswalk[26].setTexture(this->data->textures.get("dswalk27"));
			this->dswalk[27].setTexture(this->data->textures.get("dswalk28"));
			this->dswalk[28].setTexture(this->data->textures.get("dswalk29"));
			this->dswalk[29].setTexture(this->data->textures.get("dswalk30"));
			this->dswalk[30].setTexture(this->data->textures.get("dswalk31"));
			this->dswalk[31].setTexture(this->data->textures.get("dswalk32"));
			this->dswalk[32].setTexture(this->data->textures.get("dswalk33"));
			this->dswalk[33].setTexture(this->data->textures.get("dswalk34"));
			this->dswalk[34].setTexture(this->data->textures.get("dswalk35"));
			this->dswalk[35].setTexture(this->data->textures.get("dswalk36"));
			this->dswalk[36].setTexture(this->data->textures.get("dswalk37"));
			this->dswalk[37].setTexture(this->data->textures.get("dswalk38"));
			this->dswalk[38].setTexture(this->data->textures.get("dswalk39"));

			
			//resize
			for (int i = 0; i < 39; i++) {
				dswalk[i].setScale(.5, .5);
			}


			//position
			for (int i = 0; i < 39; i++) {
				dswalk[i].setPosition(240,800);
			}


			//idle

			//loading
			this->data->textures.load("dsidle001", dsidle001);
			this->data->textures.load("dsidle002", dsidle002);
			this->data->textures.load("dsidle003", dsidle003);
			this->data->textures.load("dsidle004", dsidle004);
			this->data->textures.load("dsidle005", dsidle005);
			this->data->textures.load("dsidle006", dsidle006);
			this->data->textures.load("dsidle007", dsidle007);
			this->data->textures.load("dsidle008", dsidle008);
			this->data->textures.load("dsidle009", dsidle009);
			this->data->textures.load("dsidle010", dsidle010);
			this->data->textures.load("dsidle011", dsidle011);
			this->data->textures.load("dsidle012", dsidle012);
			this->data->textures.load("dsidle013", dsidle013);
			this->data->textures.load("dsidle014", dsidle014);
			this->data->textures.load("dsidle015", dsidle015);
			this->data->textures.load("dsidle016", dsidle016);
			this->data->textures.load("dsidle017", dsidle017);
			this->data->textures.load("dsidle018", dsidle018);
			this->data->textures.load("dsidle019", dsidle019);
			this->data->textures.load("dsidle020", dsidle020);
			this->data->textures.load("dsidle021", dsidle021);
			this->data->textures.load("dsidle022", dsidle022);
			this->data->textures.load("dsidle023", dsidle023);
			this->data->textures.load("dsidle024", dsidle024);
			this->data->textures.load("dsidle025", dsidle025);
			this->data->textures.load("dsidle026", dsidle026);
			this->data->textures.load("dsidle027", dsidle027);
			this->data->textures.load("dsidle028", dsidle028);
			this->data->textures.load("dsidle029", dsidle029);
			this->data->textures.load("dsidle030", dsidle030);
			this->data->textures.load("dsidle031", dsidle031);
			this->data->textures.load("dsidle032", dsidle032);
			this->data->textures.load("dsidle033", dsidle033);
			this->data->textures.load("dsidle034", dsidle034);
			this->data->textures.load("dsidle035", dsidle035);
			this->data->textures.load("dsidle036", dsidle036);
			this->data->textures.load("dsidle037", dsidle037);
			this->data->textures.load("dsidle038", dsidle038);
			this->data->textures.load("dsidle039", dsidle039);
			this->data->textures.load("dsidle040", dsidle040);
			this->data->textures.load("dsidle041", dsidle041);
			this->data->textures.load("dsidle042", dsidle042);
			this->data->textures.load("dsidle043", dsidle043);
			this->data->textures.load("dsidle044", dsidle044);
			this->data->textures.load("dsidle045", dsidle045);
			this->data->textures.load("dsidle046", dsidle046);
			this->data->textures.load("dsidle047", dsidle047);
			this->data->textures.load("dsidle048", dsidle048);
			this->data->textures.load("dsidle049", dsidle049);
			this->data->textures.load("dsidle050", dsidle050);
			this->data->textures.load("dsidle051", dsidle051);
			this->data->textures.load("dsidle052", dsidle052);
			this->data->textures.load("dsidle053", dsidle053);
			this->data->textures.load("dsidle054", dsidle054);
			this->data->textures.load("dsidle055", dsidle055);
			this->data->textures.load("dsidle056", dsidle056);
			this->data->textures.load("dsidle057", dsidle057);
			this->data->textures.load("dsidle058", dsidle058);
			this->data->textures.load("dsidle059", dsidle059);
			this->data->textures.load("dsidle060", dsidle060);
			this->data->textures.load("dsidle061", dsidle061);
			this->data->textures.load("dsidle062", dsidle062);
			this->data->textures.load("dsidle063", dsidle063);
			this->data->textures.load("dsidle064", dsidle064);
			this->data->textures.load("dsidle065", dsidle065);
			this->data->textures.load("dsidle066", dsidle066);
			this->data->textures.load("dsidle067", dsidle067);
			this->data->textures.load("dsidle068", dsidle068);
			this->data->textures.load("dsidle069", dsidle069);
			this->data->textures.load("dsidle070", dsidle070);
			this->data->textures.load("dsidle071", dsidle071);
			this->data->textures.load("dsidle072", dsidle072);
			this->data->textures.load("dsidle073", dsidle073);
			this->data->textures.load("dsidle074", dsidle074);
			this->data->textures.load("dsidle075", dsidle075);
			this->data->textures.load("dsidle076", dsidle076);
			this->data->textures.load("dsidle077", dsidle077);
			this->data->textures.load("dsidle078", dsidle078);
			this->data->textures.load("dsidle079", dsidle079);
			this->data->textures.load("dsidle080", dsidle080);
			this->data->textures.load("dsidle081", dsidle081);
			this->data->textures.load("dsidle082", dsidle082);
			this->data->textures.load("dsidle083", dsidle083);
			this->data->textures.load("dsidle084", dsidle084);
			this->data->textures.load("dsidle085", dsidle085);
			this->data->textures.load("dsidle086", dsidle086);
			this->data->textures.load("dsidle087", dsidle087);
			this->data->textures.load("dsidle088", dsidle088);
			this->data->textures.load("dsidle089", dsidle089);
			this->data->textures.load("dsidle090", dsidle090);
			this->data->textures.load("dsidle091", dsidle091);
			this->data->textures.load("dsidle092", dsidle092);
			this->data->textures.load("dsidle093", dsidle093);
			this->data->textures.load("dsidle094", dsidle094);
			this->data->textures.load("dsidle095", dsidle095);
			this->data->textures.load("dsidle096", dsidle096);
			this->data->textures.load("dsidle097", dsidle097);
			this->data->textures.load("dsidle098", dsidle098);
			this->data->textures.load("dsidle099", dsidle099);
			this->data->textures.load("dsidle100", dsidle100);

			//getting 

			this->dsidle[0].setTexture(this->data->textures.get("dsidle001"));
			this->dsidle[1].setTexture(this->data->textures.get("dsidle002"));
			this->dsidle[2].setTexture(this->data->textures.get("dsidle003"));
			this->dsidle[3].setTexture(this->data->textures.get("dsidle004"));
			this->dsidle[4].setTexture(this->data->textures.get("dsidle005"));
			this->dsidle[5].setTexture(this->data->textures.get("dsidle006"));
			this->dsidle[6].setTexture(this->data->textures.get("dsidle007"));
			this->dsidle[7].setTexture(this->data->textures.get("dsidle008"));
			this->dsidle[8].setTexture(this->data->textures.get("dsidle009"));
			this->dsidle[9].setTexture(this->data->textures.get("dsidle010"));
			this->dsidle[10].setTexture(this->data->textures.get("dsidle011"));
			this->dsidle[11].setTexture(this->data->textures.get("dsidle012"));
			this->dsidle[12].setTexture(this->data->textures.get("dsidle013"));
			this->dsidle[13].setTexture(this->data->textures.get("dsidle014"));
			this->dsidle[14].setTexture(this->data->textures.get("dsidle015"));
			this->dsidle[15].setTexture(this->data->textures.get("dsidle016"));
			this->dsidle[16].setTexture(this->data->textures.get("dsidle017"));
			this->dsidle[17].setTexture(this->data->textures.get("dsidle018"));
			this->dsidle[18].setTexture(this->data->textures.get("dsidle019"));
			this->dsidle[19].setTexture(this->data->textures.get("dsidle020"));
			this->dsidle[20].setTexture(this->data->textures.get("dsidle021"));
			this->dsidle[21].setTexture(this->data->textures.get("dsidle022"));
			this->dsidle[22].setTexture(this->data->textures.get("dsidle023"));
			this->dsidle[23].setTexture(this->data->textures.get("dsidle024"));
			this->dsidle[24].setTexture(this->data->textures.get("dsidle025"));
			this->dsidle[25].setTexture(this->data->textures.get("dsidle026"));
			this->dsidle[26].setTexture(this->data->textures.get("dsidle027"));
			this->dsidle[27].setTexture(this->data->textures.get("dsidle028"));
			this->dsidle[28].setTexture(this->data->textures.get("dsidle029"));
			this->dsidle[29].setTexture(this->data->textures.get("dsidle030"));
			this->dsidle[30].setTexture(this->data->textures.get("dsidle031"));
			this->dsidle[31].setTexture(this->data->textures.get("dsidle032"));
			this->dsidle[32].setTexture(this->data->textures.get("dsidle033"));
			this->dsidle[33].setTexture(this->data->textures.get("dsidle034"));
			this->dsidle[34].setTexture(this->data->textures.get("dsidle035"));
			this->dsidle[35].setTexture(this->data->textures.get("dsidle036"));
			this->dsidle[36].setTexture(this->data->textures.get("dsidle037"));
			this->dsidle[37].setTexture(this->data->textures.get("dsidle038"));
			this->dsidle[38].setTexture(this->data->textures.get("dsidle039"));
			this->dsidle[39].setTexture(this->data->textures.get("dsidle040"));
			this->dsidle[40].setTexture(this->data->textures.get("dsidle041"));
			this->dsidle[41].setTexture(this->data->textures.get("dsidle042"));
			this->dsidle[42].setTexture(this->data->textures.get("dsidle043"));
			this->dsidle[43].setTexture(this->data->textures.get("dsidle044"));
			this->dsidle[44].setTexture(this->data->textures.get("dsidle045"));
			this->dsidle[45].setTexture(this->data->textures.get("dsidle046"));
			this->dsidle[46].setTexture(this->data->textures.get("dsidle047"));
			this->dsidle[47].setTexture(this->data->textures.get("dsidle048"));
			this->dsidle[48].setTexture(this->data->textures.get("dsidle049"));
			this->dsidle[49].setTexture(this->data->textures.get("dsidle050"));
			this->dsidle[50].setTexture(this->data->textures.get("dsidle051"));
			this->dsidle[51].setTexture(this->data->textures.get("dsidle052"));
			this->dsidle[52].setTexture(this->data->textures.get("dsidle053"));
			this->dsidle[53].setTexture(this->data->textures.get("dsidle054"));
			this->dsidle[54].setTexture(this->data->textures.get("dsidle055"));
			this->dsidle[55].setTexture(this->data->textures.get("dsidle056"));
			this->dsidle[56].setTexture(this->data->textures.get("dsidle057"));
			this->dsidle[57].setTexture(this->data->textures.get("dsidle058"));
			this->dsidle[58].setTexture(this->data->textures.get("dsidle059"));
			this->dsidle[59].setTexture(this->data->textures.get("dsidle060"));
			this->dsidle[60].setTexture(this->data->textures.get("dsidle061"));
			this->dsidle[61].setTexture(this->data->textures.get("dsidle062"));
			this->dsidle[62].setTexture(this->data->textures.get("dsidle063"));
			this->dsidle[63].setTexture(this->data->textures.get("dsidle064"));
			this->dsidle[64].setTexture(this->data->textures.get("dsidle065"));
			this->dsidle[65].setTexture(this->data->textures.get("dsidle066"));
			this->dsidle[66].setTexture(this->data->textures.get("dsidle067"));
			this->dsidle[67].setTexture(this->data->textures.get("dsidle068"));
			this->dsidle[68].setTexture(this->data->textures.get("dsidle069"));
			this->dsidle[69].setTexture(this->data->textures.get("dsidle070"));
			this->dsidle[60].setTexture(this->data->textures.get("dsidle071"));
			this->dsidle[71].setTexture(this->data->textures.get("dsidle072"));
			this->dsidle[72].setTexture(this->data->textures.get("dsidle073"));
			this->dsidle[73].setTexture(this->data->textures.get("dsidle074"));
			this->dsidle[74].setTexture(this->data->textures.get("dsidle075"));
			this->dsidle[75].setTexture(this->data->textures.get("dsidle076"));
			this->dsidle[76].setTexture(this->data->textures.get("dsidle077"));
			this->dsidle[77].setTexture(this->data->textures.get("dsidle078"));
			this->dsidle[78].setTexture(this->data->textures.get("dsidle079"));
			this->dsidle[79].setTexture(this->data->textures.get("dsidle080"));
			this->dsidle[80].setTexture(this->data->textures.get("dsidle081"));
			this->dsidle[81].setTexture(this->data->textures.get("dsidle082"));
			this->dsidle[82].setTexture(this->data->textures.get("dsidle083"));
			this->dsidle[83].setTexture(this->data->textures.get("dsidle084"));
			this->dsidle[84].setTexture(this->data->textures.get("dsidle085"));
			this->dsidle[85].setTexture(this->data->textures.get("dsidle086"));
			this->dsidle[86].setTexture(this->data->textures.get("dsidle087"));
			this->dsidle[87].setTexture(this->data->textures.get("dsidle088"));
			this->dsidle[88].setTexture(this->data->textures.get("dsidle089"));
			this->dsidle[89].setTexture(this->data->textures.get("dsidle090"));
			this->dsidle[90].setTexture(this->data->textures.get("dsidle091"));
			this->dsidle[91].setTexture(this->data->textures.get("dsidle092"));
			this->dsidle[92].setTexture(this->data->textures.get("dsidle093"));
			this->dsidle[93].setTexture(this->data->textures.get("dsidle094"));
			this->dsidle[94].setTexture(this->data->textures.get("dsidle095"));
			this->dsidle[95].setTexture(this->data->textures.get("dsidle096"));
			this->dsidle[96].setTexture(this->data->textures.get("dsidle097"));
			this->dsidle[97].setTexture(this->data->textures.get("dsidle098"));
			this->dsidle[98].setTexture(this->data->textures.get("dsidle099"));
			this->dsidle[99].setTexture(this->data->textures.get("dsidle100"));




			//resize
			for (int i = 0; i <100; i++) {
				dsidle[i].setScale(.5, .5);
			}


			//position
			for (int i = 0; i <100; i++) {
				dsidle[i].setPosition(240, 800);
			}



			//run

			//loading
			this->data->textures.load("dsrun01", dsrun001);
			this->data->textures.load("dsrun02", dsrun002);
			this->data->textures.load("dsrun03", dsrun003);
			this->data->textures.load("dsrun04", dsrun004);
			this->data->textures.load("dsrun05", dsrun005);
			this->data->textures.load("dsrun06", dsrun006);
			this->data->textures.load("dsrun07", dsrun007);
			this->data->textures.load("dsrun08", dsrun008);
			this->data->textures.load("dsrun09", dsrun009);
			this->data->textures.load("dsrun10", dsrun010);
			this->data->textures.load("dsrun11", dsrun011);
			this->data->textures.load("dsrun12", dsrun012);
			this->data->textures.load("dsrun13", dsrun013);
			this->data->textures.load("dsrun14", dsrun014);
			this->data->textures.load("dsrun15", dsrun015);
			this->data->textures.load("dsrun16", dsrun016);
			this->data->textures.load("dsrun17", dsrun017);

			//getting

			this->dsrun[0].setTexture(this->data->textures.get("dsrun01"));
			this->dsrun[1].setTexture(this->data->textures.get("dsrun02"));
			this->dsrun[2].setTexture(this->data->textures.get("dsrun03"));
			this->dsrun[3].setTexture(this->data->textures.get("dsrun04"));
			this->dsrun[4].setTexture(this->data->textures.get("dsrun05"));
			this->dsrun[5].setTexture(this->data->textures.get("dsrun06"));
			this->dsrun[6].setTexture(this->data->textures.get("dsrun07"));
			this->dsrun[7].setTexture(this->data->textures.get("dsrun08"));
			this->dsrun[8].setTexture(this->data->textures.get("dsrun09"));
			this->dsrun[9].setTexture(this->data->textures.get("dsrun10"));
			this->dsrun[10].setTexture(this->data->textures.get("dsrun11"));
			this->dsrun[11].setTexture(this->data->textures.get("dsrun12"));
			this->dsrun[12].setTexture(this->data->textures.get("dsrun13"));
			this->dsrun[13].setTexture(this->data->textures.get("dsrun14"));
			this->dsrun[14].setTexture(this->data->textures.get("dsrun15"));
			this->dsrun[15].setTexture(this->data->textures.get("dsrun16"));
			this->dsrun[16].setTexture(this->data->textures.get("dsrun17"));





			//resize
			for (int i = 0; i < 17; i++) {
				dsrun[i].setScale(.5, .5);
			}


			//position
			for (int i = 0; i < 17; i++) {
				dsrun[i].setPosition(240, 845);
			}

			//attack

			//loading
			this->data->textures.load("dsattack001", dsattack001);
			this->data->textures.load("dsattack002", dsattack002);
			this->data->textures.load("dsattack003", dsattack003);
			this->data->textures.load("dsattack004", dsattack004);
			this->data->textures.load("dsattack005", dsattack005);
			this->data->textures.load("dsattack006", dsattack006);
			this->data->textures.load("dsattack007", dsattack007);
			this->data->textures.load("dsattack008", dsattack008);
			this->data->textures.load("dsattack009", dsattack009);
			this->data->textures.load("dsattack010", dsattack010);
			this->data->textures.load("dsattack011", dsattack011);
			this->data->textures.load("dsattack012", dsattack012);
			this->data->textures.load("dsattack013", dsattack013);
			this->data->textures.load("dsattack014", dsattack014);
			this->data->textures.load("dsattack015", dsattack015);
			this->data->textures.load("dsattack016", dsattack016);
			this->data->textures.load("dsattack017", dsattack017);
			this->data->textures.load("dsattack018", dsattack018);
			this->data->textures.load("dsattack019", dsattack019);
			this->data->textures.load("dsattack020", dsattack020);
			this->data->textures.load("dsattack021", dsattack021);
			this->data->textures.load("dsattack022", dsattack022);
			this->data->textures.load("dsattack023", dsattack023);
			this->data->textures.load("dsattack024", dsattack024);
			this->data->textures.load("dsattack025", dsattack025);
			this->data->textures.load("dsattack026", dsattack026);
			this->data->textures.load("dsattack027", dsattack027);
			this->data->textures.load("dsattack028", dsattack028);
			this->data->textures.load("dsattack029", dsattack029);
			this->data->textures.load("dsattack030", dsattack030);
			this->data->textures.load("dsattack031", dsattack031);
			this->data->textures.load("dsattack032", dsattack032);
			this->data->textures.load("dsattack033", dsattack033);
			this->data->textures.load("dsattack034", dsattack034);
			this->data->textures.load("dsattack035", dsattack035);
			this->data->textures.load("dsattack036", dsattack036);
			this->data->textures.load("dsattack037", dsattack037);
			this->data->textures.load("dsattack038", dsattack038);
			this->data->textures.load("dsattack039", dsattack039);
			this->data->textures.load("dsattack040", dsattack040);
			this->data->textures.load("dsattack041", dsattack041);
			this->data->textures.load("dsattack042", dsattack042);
			this->data->textures.load("dsattack043", dsattack043);
			this->data->textures.load("dsattack044", dsattack044);
			this->data->textures.load("dsattack045", dsattack045);
			this->data->textures.load("dsattack046", dsattack046);
			this->data->textures.load("dsattack047", dsattack047);
			this->data->textures.load("dsattack048", dsattack048);
			this->data->textures.load("dsattack049", dsattack049);
			this->data->textures.load("dsattack050", dsattack050);
			this->data->textures.load("dsattack051", dsattack051);
			this->data->textures.load("dsattack052", dsattack052);
			this->data->textures.load("dsattack053", dsattack053);
			this->data->textures.load("dsattack054", dsattack054);
			this->data->textures.load("dsattack055", dsattack055);
			this->data->textures.load("dsattack056", dsattack056);
			this->data->textures.load("dsattack057", dsattack057);
			this->data->textures.load("dsattack058", dsattack058);
			this->data->textures.load("dsattack059", dsattack059);
			this->data->textures.load("dsattack060", dsattack060);
			this->data->textures.load("dsattack061", dsattack061);
			this->data->textures.load("dsattack062", dsattack062);
			this->data->textures.load("dsattack063", dsattack063);
			this->data->textures.load("dsattack064", dsattack064);
			this->data->textures.load("dsattack065", dsattack065);
			this->data->textures.load("dsattack066", dsattack066);
			this->data->textures.load("dsattack067", dsattack067);
			this->data->textures.load("dsattack068", dsattack068);
			this->data->textures.load("dsattack069", dsattack069);
			this->data->textures.load("dsattack070", dsattack070);
			this->data->textures.load("dsattack071", dsattack071);
			this->data->textures.load("dsattack072", dsattack072);
			this->data->textures.load("dsattack073", dsattack073);
			this->data->textures.load("dsattack074", dsattack074);
			this->data->textures.load("dsattack075", dsattack075);
			this->data->textures.load("dsattack076", dsattack076);
			this->data->textures.load("dsattack077", dsattack077);


			// getting

			this->dsattack[0].setTexture(this->data->textures.get("dsattack001"));
			this->dsattack[1].setTexture(this->data->textures.get("dsattack002"));
			this->dsattack[2].setTexture(this->data->textures.get("dsattack003"));
			this->dsattack[3].setTexture(this->data->textures.get("dsattack004"));
			this->dsattack[4].setTexture(this->data->textures.get("dsattack005"));
			this->dsattack[5].setTexture(this->data->textures.get("dsattack006"));
			this->dsattack[6].setTexture(this->data->textures.get("dsattack007"));
			this->dsattack[7].setTexture(this->data->textures.get("dsattack008"));
			this->dsattack[8].setTexture(this->data->textures.get("dsattack009"));
			this->dsattack[9].setTexture(this->data->textures.get("dsattack010"));
			this->dsattack[10].setTexture(this->data->textures.get("dsattack011"));
			this->dsattack[11].setTexture(this->data->textures.get("dsattack012"));
			this->dsattack[12].setTexture(this->data->textures.get("dsattack013"));
			this->dsattack[13].setTexture(this->data->textures.get("dsattack014"));
			this->dsattack[14].setTexture(this->data->textures.get("dsattack015"));
			this->dsattack[15].setTexture(this->data->textures.get("dsattack016"));
			this->dsattack[16].setTexture(this->data->textures.get("dsattack017"));
			this->dsattack[17].setTexture(this->data->textures.get("dsattack018"));
			this->dsattack[18].setTexture(this->data->textures.get("dsattack019"));
			this->dsattack[19].setTexture(this->data->textures.get("dsattack020"));
			this->dsattack[20].setTexture(this->data->textures.get("dsattack021"));
			this->dsattack[21].setTexture(this->data->textures.get("dsattack022"));
			this->dsattack[22].setTexture(this->data->textures.get("dsattack023"));
			this->dsattack[23].setTexture(this->data->textures.get("dsattack024"));
			this->dsattack[24].setTexture(this->data->textures.get("dsattack025"));
			this->dsattack[25].setTexture(this->data->textures.get("dsattack026"));
			this->dsattack[26].setTexture(this->data->textures.get("dsattack027"));
			this->dsattack[27].setTexture(this->data->textures.get("dsattack028"));
			this->dsattack[28].setTexture(this->data->textures.get("dsattack029"));
			this->dsattack[29].setTexture(this->data->textures.get("dsattack030"));
			this->dsattack[30].setTexture(this->data->textures.get("dsattack031"));
			this->dsattack[31].setTexture(this->data->textures.get("dsattack032"));
			this->dsattack[32].setTexture(this->data->textures.get("dsattack033"));
			this->dsattack[33].setTexture(this->data->textures.get("dsattack034"));
			this->dsattack[34].setTexture(this->data->textures.get("dsattack035"));
			this->dsattack[35].setTexture(this->data->textures.get("dsattack036"));
			this->dsattack[36].setTexture(this->data->textures.get("dsattack037"));
			this->dsattack[37].setTexture(this->data->textures.get("dsattack038"));
			this->dsattack[38].setTexture(this->data->textures.get("dsattack039"));
			this->dsattack[39].setTexture(this->data->textures.get("dsattack040"));
			this->dsattack[40].setTexture(this->data->textures.get("dsattack041"));
			this->dsattack[41].setTexture(this->data->textures.get("dsattack042"));
			this->dsattack[42].setTexture(this->data->textures.get("dsattack043"));
			this->dsattack[43].setTexture(this->data->textures.get("dsattack044"));
			this->dsattack[44].setTexture(this->data->textures.get("dsattack045"));
			this->dsattack[45].setTexture(this->data->textures.get("dsattack046"));
			this->dsattack[46].setTexture(this->data->textures.get("dsattack047"));
			this->dsattack[47].setTexture(this->data->textures.get("dsattack048"));
			this->dsattack[48].setTexture(this->data->textures.get("dsattack049"));
			this->dsattack[49].setTexture(this->data->textures.get("dsattack050"));
			this->dsattack[50].setTexture(this->data->textures.get("dsattack051"));
			this->dsattack[51].setTexture(this->data->textures.get("dsattack052"));
			this->dsattack[52].setTexture(this->data->textures.get("dsattack053"));
			this->dsattack[53].setTexture(this->data->textures.get("dsattack054"));
			this->dsattack[54].setTexture(this->data->textures.get("dsattack055"));
			this->dsattack[55].setTexture(this->data->textures.get("dsattack056"));
			this->dsattack[56].setTexture(this->data->textures.get("dsattack057"));
			this->dsattack[57].setTexture(this->data->textures.get("dsattack058"));
			this->dsattack[58].setTexture(this->data->textures.get("dsattack059"));
			this->dsattack[59].setTexture(this->data->textures.get("dsattack060"));
			this->dsattack[60].setTexture(this->data->textures.get("dsattack061"));
			this->dsattack[61].setTexture(this->data->textures.get("dsattack062"));
			this->dsattack[62].setTexture(this->data->textures.get("dsattack063"));
			this->dsattack[63].setTexture(this->data->textures.get("dsattack064"));
			this->dsattack[64].setTexture(this->data->textures.get("dsattack065"));
			this->dsattack[65].setTexture(this->data->textures.get("dsattack066"));
			this->dsattack[66].setTexture(this->data->textures.get("dsattack067"));
			this->dsattack[67].setTexture(this->data->textures.get("dsattack068"));
			this->dsattack[68].setTexture(this->data->textures.get("dsattack069"));
			this->dsattack[69].setTexture(this->data->textures.get("dsattack070"));
			this->dsattack[70].setTexture(this->data->textures.get("dsattack071"));
			this->dsattack[71].setTexture(this->data->textures.get("dsattack072"));
			this->dsattack[72].setTexture(this->data->textures.get("dsattack073"));
			this->dsattack[73].setTexture(this->data->textures.get("dsattack074"));
			this->dsattack[74].setTexture(this->data->textures.get("dsattack075"));
			this->dsattack[75].setTexture(this->data->textures.get("dsattack076"));
			this->dsattack[76].setTexture(this->data->textures.get("dsattack077"));


			//resize
			for (int i = 0; i < 77; i++) {
				dsattack[i].setScale(.5, .5);
			}


			//position
			for (int i = 0; i < 77; i++) {
				dsattack[i].setPosition(180, 750);
			}

			//howling

			//loading
			this->data->textures.load("dshowl001", dshowl001);
			this->data->textures.load("dshowl002", dshowl002);
			this->data->textures.load("dshowl003", dshowl003);
			this->data->textures.load("dshowl004", dshowl004);
			this->data->textures.load("dshowl005", dshowl005);
			this->data->textures.load("dshowl006", dshowl006);
			this->data->textures.load("dshowl007", dshowl007);
			this->data->textures.load("dshowl008", dshowl008);
			this->data->textures.load("dshowl009", dshowl009);
			this->data->textures.load("dshowl010", dshowl010);
			this->data->textures.load("dshowl011", dshowl011);
			this->data->textures.load("dshowl012", dshowl012);
			this->data->textures.load("dshowl013", dshowl013);
			this->data->textures.load("dshowl014", dshowl014);
			this->data->textures.load("dshowl015", dshowl015);
			this->data->textures.load("dshowl016", dshowl016);
			this->data->textures.load("dshowl017", dshowl017);
			this->data->textures.load("dshowl018", dshowl018);
			this->data->textures.load("dshowl019", dshowl019);
			this->data->textures.load("dshowl020", dshowl020);






			//getting


			this->dshowl[0].setTexture(this->data->textures.get("dshowl001"));
			this->dshowl[1].setTexture(this->data->textures.get("dshowl002"));
			this->dshowl[2].setTexture(this->data->textures.get("dshowl003"));
			this->dshowl[3].setTexture(this->data->textures.get("dshowl004"));
			this->dshowl[4].setTexture(this->data->textures.get("dshowl005"));
			this->dshowl[5].setTexture(this->data->textures.get("dshowl006"));
			this->dshowl[6].setTexture(this->data->textures.get("dshowl007"));
			this->dshowl[7].setTexture(this->data->textures.get("dshowl008"));
			this->dshowl[8].setTexture(this->data->textures.get("dshowl009"));
			this->dshowl[9].setTexture(this->data->textures.get("dshowl010"));
			this->dshowl[10].setTexture(this->data->textures.get("dshowl011"));
			this->dshowl[11].setTexture(this->data->textures.get("dshowl012"));
			this->dshowl[12].setTexture(this->data->textures.get("dshowl013"));
			this->dshowl[13].setTexture(this->data->textures.get("dshowl014"));
			this->dshowl[14].setTexture(this->data->textures.get("dshowl015"));
			this->dshowl[15].setTexture(this->data->textures.get("dshowl016"));
			this->dshowl[16].setTexture(this->data->textures.get("dshowl017"));
			this->dshowl[17].setTexture(this->data->textures.get("dshowl018"));
			this->dshowl[18].setTexture(this->data->textures.get("dshowl019"));
			this->dshowl[19].setTexture(this->data->textures.get("dshowl020"));

			//resize
			for (int i = 0; i < 20; i++) {
				dshowl[i].setScale(.5, .5);
			}


			//position
			for (int i = 0; i < 20; i++) {
				dshowl[i].setPosition(240, 760);
			}


		}


		void HandleInput(Event &evnt) {

			/*if (evnt.type == evnt.KeyPressed) {
				if (evnt.key.code == Keyboard::D) {
					loop++;
				}
			
				else if (evnt.key.code == Keyboard::A) {
					loop--;
				}

			}*/
		}

		void update(float dt) {

		}

		void draw() {
			/*if (loop <= 38)
				this->data->window.draw(dswalk[loop]);
			else if(loop>38 || loop <0) loop = 0;*/
		}


		int loop = 0;
		Sprite dswalk[40];
		Sprite dsidle[101];
		Sprite dsrun[18];
		Sprite dsdeath[100];
		Sprite dsattack[78];
		Sprite dshowl[21];
	private:
		GameDataRef data;
		
	};
}