/*
 * https://open.kattis.com/problems/concentration
 * Author: https://github.com/smh997/
 */

#include <bits/stdc++.h>
using namespace std;

set<int> cards;
set<int> notwin;

int N;

int ant[2000003];
int mat[2000003];

int ant_cards = 0;
int mat_cards = 0;
int ant_index = 0;
int mat_index = 0;

inline int sim(int card){
	return  (card % 2 == 0) ? (card +1) : (card - 1);
}

bool choice(bool turn){
	if(turn){
		if(mat_index < 2 * N - 1 && mat[mat_index+1] == sim(mat[mat_index])){
			cards.insert(mat[mat_index]);
			cards.insert(mat[mat_index+1]);
			mat_index += 2;
			mat_cards += 2;
			return 1;
		}
		while(cards.find(mat[mat_index]) != cards.end() && notwin.find(sim(mat[mat_index])) == notwin.end()) 
			mat_index++;
		int card = mat[mat_index];
		cards.insert(card);
		int similar = sim(card);
		auto cs = notwin.find(similar);
		if(cs == notwin.end()){
			mat_index++;
			while(cards.find(mat[mat_index]) != cards.end()) 
				mat_index++;
			cards.insert(mat[mat_index]);
			bool res = 0;
			if(mat[mat_index] == similar){ 
				mat_cards += 2;
				res = 1;
			}
			else{
				notwin.insert(card);
				auto si = notwin.find(sim(mat[mat_index]));
				if(si != notwin.end()){
					ant_cards += 2;
					notwin.erase(si);
				}
				else
					notwin.insert(mat[mat_index]);
			}
			mat_index += 1;
			return res;
		}
		else{
			notwin.erase(cs);
			mat_index += 1;
			mat_cards += 2;
			return 1;
		}
	}	
	else{
		if(ant_index < 2 * N - 1 && ant[ant_index+1] == sim(ant[ant_index])){
			cards.insert(ant[ant_index]);
			cards.insert(ant[ant_index+1]);
			ant_index += 2;
			ant_cards += 2;
			return 1;
		}
		while(cards.find(ant[ant_index]) != cards.end() && notwin.find(sim(ant[ant_index])) == notwin.end())
			 ant_index++;
		int card = ant[ant_index];
		cards.insert(card);
		int similar = sim(card);
		auto cs = notwin.find(similar);
		if(cs == notwin.end()){
			ant_index++;
			while(cards.find(ant[ant_index]) != cards.end())
				ant_index++;
			cards.insert(ant[ant_index]);
			bool res = 0;
			if(ant[ant_index] == similar){ 
				ant_cards += 2;
				res = 1;
			}
			else{
				notwin.insert(card);
				auto si = notwin.find(sim(ant[ant_index]));
				if(si != notwin.end()){
					mat_cards += 2;
					notwin.erase(si);
				}
				else{
					notwin.insert(ant[ant_index]);
				}
			}
			ant_index += 1;
			return res;
		}
		else{
			notwin.erase(cs);
			ant_index += 1;
			ant_cards += 2;
			return 1;
		}
	}
}

int main(void){

	cin >> N;
	for(int i = 0; i < 2 * N; i++)
		cin >> ant[i];
	for(int i = 0; i < 2 * N; i++)
		cin >> mat[i];

	bool turn = 0;
	while(mat_cards + ant_cards < 2 * N)
		if(!choice(turn))
			turn = !turn;
	if(mat_cards == ant_cards)
		cout << -1 << endl;
	else if(mat_cards < ant_cards)
		cout << 0 << endl;
	else
		cout << 1 << endl;

	return 0;
}
