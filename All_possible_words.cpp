// You should be using single quotes for characters. 
// Double quotes means you're using a (potentially single-character) string literal, which is represented as a const char * (pointer to constant character)
// https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/?track=SPCF-Recursion&batchId=155#ExpectOP


// Array of strings
string dial[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void pwords( int arr[] , int l ,int n ,char results[])
{
    if(l==n)
    {
        cout<<results<<" ";
        return;
    }
    for(int i=0;i<dial[arr[l]].length();i++)
    {
        results[l] = dial[arr[l]][i];
        pwords(arr,l+1,n,results);
    }
}
void possibleWords(int a[],int n)
{
    //Your code here
    char results[n];
    results[n]='\0';
    pwords(a,0,n,results);
}