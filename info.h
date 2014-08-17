typedef struct userinfo {
	char name[21];
	int job_code;
	int skill_code;
	int lv;
	int exp;
	int atk;
	int def;
	int hp;
	int money;
	int helper_num;
} Userinfo;
Userinfo Usr;
typedef struct heroinfo {
	char name[21];
	int job_code;
	int skill_code;
	int lv;
	int exp;
	int atk;
	int def;
	int hp;
} Heroinfo;
Heroinfo Hero[49];
typedef struct enemyinfo {
	char name[21];
	int job_code;
	int skill_code;
	int lv;
	int atk;
	int def;
	int hp;
} Enemyinfo;
Enemyinfo Enemy[100];
typedef struct skillinfo {
	char name[21];
	int scope;
	int damage;
	int heal;
} Skillinfo;
Skillinfo skill[100];
typedef struct tempzone {
	int hp;
} temp;
temp Tmp[3];
void setUsr(unsigned char job_code, unsigned char skill_code) {
	Usr.job_code=job_code;
	Usr.skill_code=skill_code;
	Usr.lv=1;
	Usr.exp=300;
	Usr.atk=150;
	Usr.def=50;
	Usr.hp=1000;
	Usr.money=10000;
	Usr.helper_num=0;
}
void setHero(int n, unsigned char job_code, unsigned char skill_code) {
	Hero[n].job_code=job_code;
	Hero[n].skill_code=skill_code;
	Hero[n].lv=1;
	Hero[n].exp=300;
	Hero[n].atk=150;
	Hero[n].def=50;
	Hero[n].hp=1000;
}
void setEnemy(int n, int lv, unsigned char job_code, unsigned char skill_code) {
while(n!=0) {
	n--;
	Enemy[n].job_code=job_code;
	Enemy[n].skill_code=skill_code;
	Enemy[n].lv=lv;
	Enemy[n].atk=100+lv*10;
	Enemy[n].def=30+lv*5;
	Enemy[n].hp=500+lv*25;
}
}
void setSkill(int n,int scope, int damage, int heal) {
	skill[n].scope=scope;
	skill[n].damage=damage;
	skill[n].heal=heal;
}

