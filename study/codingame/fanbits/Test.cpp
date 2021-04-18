//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

// Author: @GoracioNewport
  
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 1791791791;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

struct Entity {
	ll id;
	string type; // WIZARD, OPPONENT_WIZARD, SNAFFLE
	ll x, y, xv, yv; // cords, speed
	ll state; // 1 - grabbed, 0 - else

	bool operator < (Entity a) {
		if (a.type == "") return true;
		return id < a.id;
	}
};

struct Ball {
	ll id, x, y, xv, yv, state;
};

ld getDist(p64 a, p64 b) {
	return hypot(abs(a.fi - b.fi), (a.se - b.se));
}

const bool debug = true;

int main() {

	ll myTeamId;
	cin >> myTeamId; cin.ignore();
	// 0 - left, 1 - right;

	ll gateX = 16000;
	ll enemyGate = 1;
	ll gateY = 3750;
	if (myTeamId) {
		gateX = 1;
		enemyGate = 16000;
	}

	while(true) {
		ll myScore, myMagic, opScore, opMagic;
		cin >> myScore >> myMagic >> opScore >> opMagic;
		ll n;
		cin >> n;
		vector <Entity> ens(20, {-1, "", -1, -1, -1, -1, -1});
		vector <Ball> balls;
		if (debug) cerr << "Initialization..." << endl;
		forn(z,n) {
			// cerr << z << endl;
			Entity i;
			cin >> i.id >> i.type >> i.x >> i.y >> i.xv >> i.yv >> i.state;
			ens[i.id] = i;
		} // sort(all(ens));
		// cerr << "Shit" << endl;
		ll fiWizId = -1, seWizId = -1;

		ll snafCount = 0;

		for (auto &i : ens) {
			// if (i.type == '') continue;
			if (i.type == "SNAFFLE") {
				snafCount++;
				balls.pb({i.id, i.x, i.y, i.xv, i.yv, i.state});
			}

			if (i.type == "WIZARD") {
				if (fiWizId == -1) fiWizId = i.id;
				else seWizId = i.id;
			}
		}

		if (debug) cerr << "Initialization Finished. Picking Targets..." << endl;

		if (fiWizId > seWizId) swap(fiWizId, seWizId);

		ll fiWizX = ens[fiWizId].x;
		ll fiWizY = ens[fiWizId].y;
		ll seWizX = ens[seWizId].x;
		ll seWizY = ens[seWizId].y;

		ll grabFi = -1, grabSe = -1;
		vector <pair <ld, ll>> snafDistFi;
		vector <pair <ld, ll>> snafDistSe;
		
		for (auto &i : balls) snafDistFi.pb({getDist({i.x,i.y}, {fiWizX, fiWizY}), i.id});
		for (auto &i : balls) snafDistSe.pb({getDist({i.x,i.y}, {seWizX, seWizY}), i.id});	
		
		sort(all(snafDistFi));
		sort(all(snafDistSe));

		grabFi = snafDistFi[0].se;
		grabSe = snafDistSe[0].se;



		if (grabFi == grabSe) {
			for (auto &i : ens) {
				if (i.type == "OPPONENT_WIZARD") {
					grabFi = i.id;
					break;
				}
			}
		}

		if (debug) { // DEBUG
			cerr << "Entity list: " << endl;
			for (auto &i : ens) {
				cerr << i.id << ' ' << i.type << ' ' << i.x << ' ' << i.y << endl;
			}

			cerr << "First target: " << grabFi << endl;
			cerr << "Second target: " << grabSe << endl;


		}

		// for (auto &i : ens) {
		// 	if (i.type == "SNAFFLE") {
		// 		if (grabFi == -1) {
		// 			grabFi = i.id;
		// 		} else if (grabSe == -1) {
		// 			grabSe = i.id;
		// 		}
		// 	}
		// } for (auto &i : ens) {
		// 	if (i.type == "OPPONENT_WIZARD") {
		// 		if (grabFi == -1) {
		// 			grabFi = i.id;
		// 		} else if (grabSe == -1) {
		// 			grabSe = i.id;
		// 		}
		// 	}
		// } 

		// FIRST WIZARD

		const ll MIN_THROW_POWER = 500;;
		const ll MIN_MOVE_POWER = 150;

		const ll MAX_THROW_POWER = 500;
		const ll MAX_MOVE_POWER = 150;

		const ll MIN_TRIGGER_DISTANCE = 4000;

		const ll MAX_ACCIO_RADIUS = 4000;


		if (myMagic >= 15) {
			vector <pair <ld, ll>> balDistFi;
			
			for (auto &i : balls) if (getDist({i.x,i.y}, {fiWizX, fiWizY}) <= MAX_ACCIO_RADIUS) balDistFi.pb({getDist({i.x,i.y}, {fiWizX, fiWizY}), i.id});
			
			sort(all(balDistFi));

			for (auto &i : balls) {
				if ((getDist({i.x,i.y}, {enemyGate, gateY}) <= MIN_TRIGGER_DISTANCE) && (getDist({i.x,i.y}, {fiWizX, fiWizY}) <= MAX_ACCIO_RADIUS)) {
					balDistFi.pb({0,i.id});
					break;
				}
			}
			if (sz(balDistFi)) cout << "ACCIO " << balDistFi.back().se << endl;
			else {
				if (myTeamId) cout << "PETRIFICUS 0" << endl; 
				else cout << "PETRIFICUS 2" << endl; 
			}

		}

		else if (ens[fiWizId].state == 1) {
			ld d = getDist({ens[fiWizId].x, ens[fiWizId].y}, {gateX, gateY});
			ll power = ceil((d / 17000) * MAX_THROW_POWER);
			power = min(power, MAX_THROW_POWER);
			power = max(power, MIN_THROW_POWER);

			if (!myTeamId) {
				if (fiWizX <= 6000) {
					ll Y;
					if (fiWizY >= 3750) Y = 7500;
					else Y = 0;
					cout << "THROW 10000 " << Y << ' ' << power << endl;
				} else cout << "THROW " << gateX << ' ' << gateY << ' ' << power << endl;
			} else {
				if (fiWizX >= 10000) {
					ll Y;
					if (fiWizY >= 3750) Y = 7500;
					else Y = 0;
					cout << "THROW 6000 " << Y << ' ' << power << endl; 
				} else cout << "THROW " << gateX << ' ' << gateY << ' ' << power << endl; 
			}
		} else {
			ld d = getDist({ens[fiWizId].x, ens[fiWizId].y}, {ens[grabFi].x, ens[grabFi].y});
			ll power = ceil((d / 17000) * MAX_MOVE_POWER);
			power = min(power, MAX_MOVE_POWER);
			power = max(power, MIN_MOVE_POWER);
			cout << "MOVE " << ens[grabFi].x << ' ' << ens[grabFi].y << ' ' << power << endl;
		}



		// SECOND WIZARD

		// if (myMagic >= 10) {

		// 	vector <pair <ld, ll>> enDistFi;
		// 	vector <pair <ld, ll>> enDistSe;
			
		// 	for (auto &i : ens) if (i.type == "OPPONENT_WIZARD") enDistFi.pb({getDist({i.x,i.y}, {fiWizX, fiWizY}), i.id});
		// 	for (auto &i : ens) if (i.type == "OPPONENT_WIZARD") enDistSe.pb({getDist({i.x,i.y}, {seWizX, seWizY}), i.id});
			
		// 	sort(all(enDistFi));
		// 	sort(all(enDistSe));

		// 	if (enDistFi[0].fi <= MIN_TRIGGER_DISTANCE || enDistSe[0].fi <= MIN_TRIGGER_DISTANCE) myMagic -= 10;

		// 	if (enDistFi[0].fi <= MIN_TRIGGER_DISTANCE) cout << "PETRIFICUS " << enDistFi[0].se << endl;
		// 	else if (enDistSe[0].fi <= MIN_TRIGGER_DISTANCE) cout << "PETRIFICUS " << enDistSe[0].se << endl;
		// 	else {

		// 		vector <pair <ld, ll>> balDistFi;
		// 		vector <pair <ld, ll>> balDistSe;
				
		// 		for (auto &i : ens) if (i.type == "BLUDGER") balDistFi.pb({getDist({i.x,i.y}, {fiWizX, fiWizY}), i.id});
		// 		for (auto &i : ens) if (i.type == "BLUDGER") balDistSe.pb({getDist({i.x,i.y}, {seWizX, seWizY}), i.id});
				
		// 		sort(all(balDistFi));
		// 		sort(all(balDistSe));

		// 		ll target;

		// 		if (balDistFi[0] < balDistSe[0]) target = balDistFi[0].se;
		// 		else target = balDistSe[0].se;

		// 		cout << "OBLIVIATE " << target << endl;
		// 		myMagic -= 5;
		// 	}
		// }

		if (ens[seWizId].state == 1) {

			p64 AAA = {-1, -1};

			for (auto &i : balls) {
				if ((getDist({i.x,i.y}, {enemyGate, gateY}) <= MIN_TRIGGER_DISTANCE) && (getDist({i.x,i.y}, {fiWizX, fiWizY}) <= MAX_ACCIO_RADIUS)) {
					AAA = {0,i.id};
					break;
				}
			}

			if (AAA.fi != -1 && myMagic >= 15) {
				cout << "ACCIO " << AAA.se << endl;
			} else {


				ld d = getDist({ens[seWizId].x, ens[seWizId].y}, {gateX, gateY});
				ll power = ceil((d / 17000) * MAX_THROW_POWER);
				power = min(power, MAX_THROW_POWER);
				power = max(power, MIN_THROW_POWER);
				if (!myTeamId) {
					if (fiWizX <= 6000) {
						ll Y;
						if (fiWizY >= 3750) Y = 7500;
						else Y = 0;
						cout << "THROW 10000 " << Y << ' ' << power << endl;
					} else cout << "THROW " << gateX << ' ' << gateY << ' ' << power << endl;
				} else {
					if (fiWizX >= 10000) {
						ll Y;
						if (fiWizY >= 3750) Y = 7500;
						else Y = 0;
						cout << "THROW 6000 " << Y << ' ' << power << endl; 
					} else cout << "THROW " << gateX << ' ' << gateY << ' ' << power << endl; 
				}
			}
		} else {
			ld d = getDist({ens[seWizId].x, ens[seWizId].y}, {ens[grabSe].x, ens[grabSe].y});
			ll power = ceil((d / 17000) * MAX_MOVE_POWER);
			power = min(power, MAX_MOVE_POWER);
			power = max(power, MIN_MOVE_POWER);
			cout << "MOVE " << ens[grabSe].x << ' ' << ens[grabSe].y << ' ' << power << endl;
		}


	}


}
