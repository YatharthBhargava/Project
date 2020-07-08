#include<bits/stdc++.h>
#include <windows.h>
#include<iostream>
#include <fstream>
#define ff first
#define ss second
#define endl "\n"
#define ll long long
#define pb push_back
#define mp make_pair
#define loop(i,a,b) for(int i = (a); i < (b); i++)
#define loopr(i,a,b) for(ll i = (a); i <= (b); i--)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
vector<string> names;// your new names buffer
std::vector<pair<string,string> > data;// this will store the data and act as our DiskStorage with ff being the name and ss being the actual data
std::vector<ll> writes;// this will store the no of writes at any index in our DiskStorage
map<string,ll> nti;// maps the name of each file and the index on DS where it is stored
multimap<ll,ll> wti;// stores the writes at each index on DS
void Insert(string s){
	if(data.size() <= 5){
		s.append(".txt");
		map<string,ll>::iterator it;
		it = nti.find(s);
		if(it != nti.end()){
			cout << "Already in DiskStorage " << endl;
		}else{

			std::ifstream ifs(s.c_str());
  			std::string content( (std::istreambuf_iterator<char>(ifs) ),(std::istreambuf_iterator<char>()    ) );
  			data.pb(mp(s,content));
  			writes.pb(1);
  			nti[s] = (int)data.size() -1 ;
  			wti.insert(mp(1,(int)data.size() -1 ));
		}

	}else{
		cout << "DiskStorage is full !\n";
	}

}
void Update(string s){
	s += ".txt";
	std::map<string, ll>::iterator it = nti.find(s);
	if(it != nti.end()){
		ll ind = nti[s];
		if(writes[ind] <= 10){
			
		}
	}else{
		cout << "File is not present !" << endl;
	}

}
void Fetch(string s){
	map<string,ll> :: iterator it;
	s += ".txt";
	it = nti.find(s);

	if(it == nti.end()){
		cout << "File not present !"<< endl;
		return ;
	}
	ll ind = nti[s];
	cout << "This is content of file : "<< s << endl;
	cout << data[ind].ss<< endl;
	cout << "Content of file : " << s << "is above this line ." << endl;
}
void query(){
	while(true){
		cout << "Files in the current Directory are listed below : " << endl;
		loop(i,0,names.size())cout << names[i] << endl;
		cout << "Features this API provides :"<< endl;
		cout << "1.Fetch\n2.Update\n3.Insert\n4.Exit\n";
		cout << "Please select any :\n" ;
		ll req ;cin >> req ;
		if(req == 1){
			string s;
			cout << "Please mention the file that you want to Fetch: " ;
			cin >> s;
			cout << endl;
			Fetch(s);
		}else if(req == 2){
			string s;
			cout << "Please mention the file that you want to Update: " ;
			cin >> s;
			cout << endl;
			Update(s);
		}else if(req == 3){
			string s;
			cout << "Please mention the file that you want to Insert: " ;
			cin >> s;
			cout << endl;
			Insert(s);
		}else if(req == 4){
			break;
		}else{
			break;
		}
	}
	return ;
}
int main(int argc, char *argv[])
{
	// #ifndef ONLINE_JUDGE
	// 	freopen("in.txt", "r", stdin);
	// 	freopen("out.txt", "w", stdout);
	// #endif
    //  NOTE:  you need to put a '*' wildcard character in the search string.  This was your biggest problem:
    static const char* chFolderpath = "C:\\Users\\Yatharth\\official\\IIT Kanpur\\Project\\*.txt";  // no need to copy this into a buffer, just use a const
      

    HANDLE hFind;
    WIN32_FIND_DATAA data2; // <- WIN32_FIND_DATAA if using char strings (instead of TCHAR strings)
    hFind = FindFirstFileA(chFolderpath, &data2);  // <- FindFirstFileA if using char strings (instead of TCHAR strings)
    ll skip = 0;
    
    if (hFind != INVALID_HANDLE_VALUE){
    	if(data2.cFileName == "in.txt" or data2.cFileName == "out.txt"){
    		;
        }else{
        	names.push_back(data2.cFileName);
        }
    }
    while( FindNextFileA( hFind, &data2 ) ){
    	if(data2.cFileName == "in.txt" or data2.cFileName == "out.txt"){
    		;
        }else{
        	names.push_back(data2.cFileName);
        }
    }

    FindClose( hFind ); 
    
    // loop(i,0,names.size()){
    // 	cout << names[i] << endl;
    // }
    query();
    
    system("PAUSE");
    return EXIT_SUCCESS;
}