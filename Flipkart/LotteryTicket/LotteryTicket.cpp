string solve(vector<string> t, string ds, int k){
    //TODO
}

int main(){
    int n;
    cin>>n;
    vector<string> tickets(n);
    
    for(int i=0;i<n;i++)
        cin>>tickets[i];
    
    string drawString;
    cin>>drawString;
    
    int tolerance;
    cin>>tolerance;
    
    cout<<solve(tickets, drawString, tolerance);
}
