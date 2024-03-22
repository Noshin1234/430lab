
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<vector>

using namespace std ;

int bucketSize = 2;
int bucketNum = 2 ;
vector<vector<string>>data(bucketNum );

int hashFunction(string s)

{

	int S = 0;


	for(int i = 0; i < s.size(); i++)
	{

		S = S+ s[i];
	}

    return S % bucketNum ;
}



bool bucketfill(string s)
{
int index=hashFunction(s);
for(int i=0;i<bucketNum;i++){
    if(data[index].size() <bucketSize){
    return false;
}
}
return true;
}
void reallocate(string s){
vector<vector<string>>*data=new vector<vector<string>>[int(bucketNum*2.5];
        for(int i=0;i<bucketNum;i++){
                for(int j=0;j<data[index].size();j++){
                        if(bucketNum==data[index].size()){

             bucketSize =bucketSize *2.5;
        }
                }

void insertItem(string s)
{
    int index = hashFunction(s) ;

    if(data[index].size() < bucketSize){
        data[index].push_back(s) ;
        cout << "Successfully inserted" << endl ;
    }
    if(bucketfill){
        reallocate(s);
    }

        }


    else{
        cout << "Bucket Overflow, insertion failed" << endl ;
    }
}

int searchItem(string s)
{
    int index = hashFunction(s) ;
    for(int i = 0 ; i < data[index].size() ; i++)
    {
        if(data[index][i] == s){
            cout << "found at: " << index << " " << i<< endl ;
            return i ;
        }
    }
    return -1 ;
}


void deleteItem(string s) {
    int index = hashFunction(s);
    int position = searchItem(s);


    if (position != -1) {
        vector<string>::iterator it;
        it = data[index].begin() + position;
        data[index].erase(it) ;
        cout << "Successfully deleted value: " << s << endl;
    } else {
        cout << "Value " << s << " not found, deletion is not possible" << endl;
    }
}




void view()
{
    for(int i = 0 ; i < bucketNum ; i++){
        if(data[i].size() > 0){

   cout << "Bucket " << i << ": " ;
            for(int j = 0 ; j < data[i].size() ; j++){
                cout << data[i][j] << " " ;
            }
         cout << endl ;
        }

    }
}
int main()
{
    int choice ;
    string department ;
    while(true)
    {
        cout << "Press 1 for insert 2 for search 3 for view 4 for delete and any key for exit" << endl ;
        cout << "Choice: " ;
        cin >> choice ;
        if(choice == 1){

            cout<< "department: " ;


            cin>>department;
            insertItem(department) ;
        }
        else if(choice == 2){
            cout << "search Key: " ;

            cin>>department;
            int n = searchItem(department) ;
            if(n == -1) cout << "Not Found" << endl ;
        }

        else if(choice == 3){
            view() ;
        }
        else if(choice == 4){
            cout << "search Key: " ;

            cin>>department;
            deleteItem(department) ;
        }

        else return 0 ;
    }

    return 0;
}

