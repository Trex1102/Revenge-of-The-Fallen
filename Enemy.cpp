#include "Enemy.h"

void rotf::Enemy::Init()
{


	// loading
	//enemy1
	this->data->textures.load("enemy1", enemy01);
	


	// getting 
	this->enemy1[0].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[1].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[2].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[3].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[4].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[5].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[6].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[7].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[8].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[9].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[10].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[11].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[12].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[13].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[14].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[15].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[16].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[17].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[18].setTexture(this->data->textures.get("enemy1"));
	this->enemy1[19].setTexture(this->data->textures.get("enemy1"));
	// resizing
	
	
	enemy1[0].setScale(2, 2);
	enemy1[1].setScale(2, 2);

	enemy001_pos.push_back(make_pair(2000, 800));
	enemy001_entry.push_back(make_pair(5, false));
	enemy001_hp.push_back(1000);

	/*enemy001_pos.push_back(make_pair(2000, 800));
	enemy001_entry.push_back(make_pair(8, false));*/

	// bullet
	//this->data->textures.load("bullet", venom);

	//this->bullet[0].setTexture(this->data->textures.get("bullet"));

	bullet.loadFromFile(venom);
	bullets[0].setTexture(bullet);
	bullets[1].setTexture(bullet);
	bullets[2].setTexture(bullet);
	bullets[3].setTexture(bullet);
	bullets[4].setTexture(bullet);
	bullets[5].setTexture(bullet);
	bullets[6].setTexture(bullet);
	bullets[7].setTexture(bullet);
	bullets[8].setTexture(bullet);
	bullets[9].setTexture(bullet);
	bullets[10].setTexture(bullet);
	bullets[11].setTexture(bullet);
	bullets[12].setTexture(bullet);
	bullets[13].setTexture(bullet);
	bullets[14].setTexture(bullet);
	bullets[15].setTexture(bullet);
	bullets[16].setTexture(bullet);
	bullets[17].setTexture(bullet);
	bullets[18].setTexture(bullet);
	bullets[19].setTexture(bullet);
	bullets[20].setTexture(bullet);
	bullets[21].setTexture(bullet);
	bullets[22].setTexture(bullet);
	bullets[23].setTexture(bullet);
	bullets[24].setTexture(bullet);
	bullets[25].setTexture(bullet);
	bullets[26].setTexture(bullet);
	bullets[27].setTexture(bullet);
	bullets[28].setTexture(bullet);
	bullets[29].setTexture(bullet);
	bullets[30].setTexture(bullet);
	bullets[31].setTexture(bullet);
	bullets[32].setTexture(bullet);
	bullets[33].setTexture(bullet);
	bullets[34].setTexture(bullet);
	bullets[35].setTexture(bullet);
	bullets[36].setTexture(bullet);
	bullets[37].setTexture(bullet);
	bullets[38].setTexture(bullet);
	bullets[39].setTexture(bullet);
	bullets[40].setTexture(bullet);
	bullets[41].setTexture(bullet);
	bullets[42].setTexture(bullet);
	bullets[43].setTexture(bullet);
	bullets[44].setTexture(bullet);
	bullets[45].setTexture(bullet);
	bullets[46].setTexture(bullet);
	bullets[47].setTexture(bullet);
	bullets[48].setTexture(bullet);
	bullets[49].setTexture(bullet);
}

void rotf::Enemy::Draw()
{
	//enemy001



	
	

	//enemy002


	//enemy003

	if (enemy001_pos.size() != 0 && enemy001_entry[0].second == true) {
		this->data->window.draw(enemy1[0]);

	}

	if (!enemy001_bullet.empty()) {
		for (int i = 0; i < enemy001_bullet.size() && i < 50; i++) {
			

			this->data->window.draw(bullets[i]);
		}
	}
}

