#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<cstdlib> 
using namespace std;

class poker	
{
	public: 
	
	int CashinAmount;
	int money;
	int pot;
	
	
	std::vector<string> deck;
	std::vector<int> dealt_cards;
	std::vector<string> hand; 
	std::vector<string> table;
	
	poker();
	void play(); 
	
	void reset_deck();
	string deal_card(); 
	void get_hand();
	void show_hand();
	
	void bet();
	
	void preflop_equity(); 
	void show_equity(); 
	
	void show_flop(); 
	void show_next(); 
	
	bool toak_(vector<string> match); 
	bool twopair_(vector<string> match);
	bool pair_(vector<string> match); 
	
	
};

bool poker::toak_(vector<string> match) 
{
	int si; 
	si=match.size();
	
	bool toak=false; 
	
	char num, type, numt, typet;
	string test, testt; 
	
	int pair;
	
	for(int k=0; k<si-1;k++)
	{
		pair=0; 
		
		test = match[k]; 
		num=test.at(0); 
		type=test.at(1); 
		
		for(int l=k+1; l<si; l++) 
		{ 
			
			testt=match[l]; 
			numt=testt.at(0); 
			typet=testt.at(1); 
			
			if(num==numt)
		    {
		    	pair++; 
		    } 
		    
		    
		    if(pair==2 && num==numt){
		    	toak=true;
		    	goto found; 
		    }
		    
		    
		} 
	
	}
	
	found:
	return toak;
	
} 

bool poker::twopair_(vector<string> match) 
{
	int si; 
	si=match.size();
	
	bool twopair=false; 
	
	char num, type, numt, typet;
	string test, testt; 
	
	int thatsapair; 
	
	for(int k=0; k<si-1;k++)
	{
		// J 3 3 5 6 6
			
		test = match[k]; 
		num=test.at(0); 
		type=test.at(1); 
		
		for(int l=k+1; l<si; l++) 
		{ 
			
			testt=match[l]; 
			numt=testt.at(0); 
			typet=testt.at(1); 
			
			if(num==numt)
		    {
		    	thatsapair++; 
		    } 
		    
		    
		    if(thatsapair==2){
		    	twopair=true;
		    	goto found; 
		    }
		    
		    
		} 
	
	}
	
	found:
	return twopair;
} 

bool poker::pair_(vector<string> match) 
{
	int si; 
	si=match.size();
	
	bool pair=false; 
	
	
	char num, type, numt, typet;
	string test, testt; 
	
	
	for(int k=0; k<si-1;k++)
	{
		// J 9 3 5 6 6
			
		test = match[k]; 
		num=test.at(0); 
		type=test.at(1); 
		
		for(int l=k+1; l<si; l++) 
		{ 
			
			testt=match[l]; 
			numt=testt.at(0); 
			typet=testt.at(1); 
			
			if(num==numt)
		    {
		    	pair=true;
		    	goto found;
		    } 
		    
		    
		} 
	
	}
	
	found:
	return pair;
} 

void poker::show_equity()
{
	//combine hand and table 
	vector<string> match;
	
	int hsi, tsi;
	
	hsi=hand.size();
	tsi=table.size(); 
	
	for(int i=0; i<hsi; i++) 
	{
		match.push_back(hand[i]); 
	} 
	
	for(int j=0; j<tsi; j++)
	{
		match.push_back(table[j]);
	}
	
	
	//find # matches within match<> 
	
	
	
	
	if(toak_(match))
	{
		cout<<"Three of a kind";
	}
	else if(twopair_(match))
	{
		cout<<"Two Pair"; 
	}
	else if(pair_(match))
	{
		cout<<"One pair";
	} 
	else { 
		cout<<"High Card";
	} 
	
	
	cout<<"\n\n"; 
	
}

void poker:: preflop_equity()
{
	
}




void poker::show_flop()
{ 
	string b1; 
	
	string c1, c2, c3;
	
	b1= deal_card(); 
	
	c1=deal_card(); 
	c2=deal_card(); 
	c3=deal_card(); 
	
	table.push_back(c1);
	table.push_back(c2);
	table.push_back(c3); 
	
	int si;
	si=table.size(); 
	
	cout<<"\n[ ";
	
	for(int i=0; i<si; i++)
	     cout<<table[i]<<" "; 
	
	cout<<"]\n\n"; 
	
} 

void poker::show_next()
{
	string b1; 
	
	string c1; 
	
	b1=deal_card(); 
	c1=deal_card(); 
	
	table.push_back(c1); 
	
	int si;
	si=table.size(); 
	
	cout<<"[ "; 
	
	for(int i=0; i<si; i++)
	     cout<<table[i]<<" "; 
	
	cout<<"]\n\n"; 
	
	
	
} 


void poker::bet()
{
	int amount;
	cout<<"Enter Bet Amount \n:";
	cin>> amount; 
	int enoughmoney=1;
	
	while(enoughmoney)
	{ 
		if(amount>money)
		{
		cout<<"Not Enough Money\nEnter Bet Amount \n:";
			cin>>amount; 
		 }
		 else{
		 	enoughmoney=0;
		 }
	 } 
	 
	 money=money-amount;
	 pot=pot+amount;
	
}

void poker::show_hand()
{
	cout<<"\nH[";
	cout<<hand[0]<<" "<<hand[1]<<"]\n"; 
}

void poker:: play()
{
	string move; 
	
	while(money>0)
	{
		
		
		pot=0; 
		
		//cout<<money<<"\n"; 
		
		reset_deck();
		get_hand();
		show_hand();
		
		//cout<<money<<"\n"; 
		preflop_equity(); 
		
		
		cout<<"\n:";
		cin>>move;
		
		if(move=="n")
		{
			show_flop(); 
			show_equity(); 
			
		} 
		else if(move=="x")	
		{
			break;
		}
		
		else
		{
			cout<<"unclear input-automatic fold\n";
		}
		
		
		cout<<"\n:";
		cin>>move;
		show_hand();
		
		if(move=="n")
		{
			show_next(); 
			show_equity(); 
			
		} 
		else if(move=="x")	
		{
			break;
		}
		
		else
		{
			cout<<"unclear input-automatic fold\n";
		}
		
		
		cout<<"\n:";
		cin>>move;
		show_hand();
		
		if(move=="n")
		{
			show_next(); 
			show_equity(); 
			
		} 
		else if(move=="x")	
		{
			break;
		}
		
		else
		{
			cout<<"unclear input-automatic fold\n";
		}
		
		
		
		
	}
	
	//cout<<"chips: "<<money; 
	
}


void poker::get_hand()
{
	std::string c1;
	std::string c2; 
	
	c1=deal_card();
	c2=deal_card();
	
	hand.push_back(c1);
	hand.push_back(c2); 
	
}
void poker::reset_deck(){
	
	deck.clear();
	hand.clear();
	dealt_cards.clear();
	table.clear(); 
	
	std::vector<string> type;
	std::vector<string> value;
	
	
	type.push_back("d");
	type.push_back("s");
	type.push_back("h");
	type.push_back("c");
	
	std::string v;
	
	for(int i=2; i<=10; i++)
	{
		v=std::to_string(i);
		value.push_back(v);
	}
	
	value.push_back("j");
	value.push_back("q");
	value.push_back("k");
	value.push_back("a");
	
	std::string card;
	
	int i, j;
	
	i=value.size();
	j=type.size();
	
	for(int k=0; k<i; k++) 
	{
		for(int d=0; d<=3; d++)
		{
			card=value[k]+type[d];
			deck.push_back(card);
		}
		
	}
	
}



poker::poker()
{
	 cout<<"Equity Calculator: n for next \n";
     cout<<"Cash in Chips: ";
     cin>> CashinAmount; 
     money=CashinAmount;
     cout<<"\n\n\n";
     play();
	 
}


string poker::deal_card()
{
	//pick random card from deck 
	//remove card from deck
	//return card 
	int cards;
	int thecard; 
	int dealt;
	
	bool different = 1;
	int check;
	
    std::string card; 
    
    cards=deck.size(); 
	thecard=rand() % cards; 
	
	dealt=dealt_cards.size();
	
	if(dealt==0)
	{
		dealt_cards.push_back(thecard);
		card=deck[thecard]; 
	    return card;
	}
	
	else{
	
	    while(different)
	    {
	    	check = 0; 
	    	
		    for(int i=0; i<dealt; i++)
		    { 
		    	if(thecard==dealt_cards[i])
		    	{
		    		thecard=rand() % cards; 
		    		check=1;
		    		break;
		    	}
		    }
		    
		    if(check==0)
		    {
		    	different=0;
		    }
		    
	    }
	}
	
	
	
    dealt_cards.push_back(thecard);
	card=deck[thecard]; 
	return card;
	
} 


int main()
{
	poker player;
	
}
