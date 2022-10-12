/*the largest number
that can be made from elements of the
multipleay which is divisible by 3 */

#include<bits/stdc++.h>
using namespace std;

// Maximum no.of digits
#define MAX_SIZE 10
void Sort_multipleay_with_Counts(int multiple[], int n)
{
	
	int count[MAX_SIZE] = {0};
	for (int i = 0; i < n; i++)
		count[multiple[i]]++;

	int index = 0;
	for (int i = 0; i < MAX_SIZE; i++)
		while (count[i] > 0)
			multiple[index++] = i, count[i]--;

}
bool Remove_and_Printelements(int multiple[], int n, int i1,
										int i2 = -1)                //i1 - index 1  i2 - index 2
{
	for (int i = n-1; i >=0; i--)
		if (i != i1 && i != i2)
			cout << multiple[i] ;
}
bool LargestMultiple(int multiple[], int n)
{
	// Sum of all multipleay elements 
    //By divisibility rule of 3 

	int sum = accumulate(multiple, multiple+n, 0);

	// Sort multipleay element in increasing order

	Sort_multipleay_with_Counts(multiple, n);
	
	// Sum is divisible by 3 , no need to
	// delete an element
	if (sum%3 == 0)
	{
		Remove_and_Printelements(multiple,n,-1,-1);
		return true ;
	}
	int remainder = sum % 3;

	/* If remainder is '1', we have to delete either
	one element of remainder '1' or two elements
	  of remainder '2'*/
	if (remainder == 1)
	{
		int Remainder_2[2];
		Remainder_2[0] = -1, Remainder_2[1] = -1;
		// Traverse multipleay elements
		for (int i = 0 ; i < n ; i++)
		{
			// Store first element of remainder '1'
			if (multiple[i]%3 == 1)
			{
				Remove_and_Printelements(multiple, n, i);
				return true;
			}

			if (multiple[i]%3 == 2)
			{
				// If this is first occurrence of remainder 2
				if (Remainder_2[0] == -1)
					Remainder_2[0] = i;

				// If second occurrence
				else if (Remainder_2[1] == -1)
					Remainder_2[1] = i;
			}
		}

		if (Remainder_2[0] != -1 && Remainder_2[1] != -1)
		{
			Remove_and_Printelements(multiple, n, Remainder_2[0], Remainder_2[1]);
			return true;
		}
	}

	// If remainder is '2', we have to delete either
	// one element of remainder '2' or two elements
	// of remainder '1'
	else if (remainder == 2)
	{
		int Remainder_1[2];
		Remainder_1[0] = -1, Remainder_1[1] = -1;

		// traverse multipleay elements
		for (int i = 0; i < n; i++)
		{
			// store first element of remainder '2'
			if (multiple[i]%3 == 2)
			{
				Remove_and_Printelements(multiple, n, i);
				return true;
			}

			if (multiple[i]%3 == 1)
			{
				// If this is first occurrence of remainder 1
				if (Remainder_1[0] == -1)
					Remainder_1[0] = i;

				// If second occurrence
				else if (Remainder_1[1] == -1)
					Remainder_1[1] = i;
			}
		}

		if (Remainder_1[0] != -1 && Remainder_1[1] != -1)
		{
			Remove_and_Printelements(multiple, n, Remainder_1[0], Remainder_1[1]);
			return true;
		}
	}

	cout << "NO COMBINATION EXISTS"<<endl;
	return false;
}

// Driver code
int main()
{
	int n;
    cin>>n;
    
    if(n>=1 && n<=10000){
    int multiple[n];
    if(n ==1){
        cin>>multiple[0];
        if(multiple[0]%3 != 0){
             cout<<"NO COMBINATION POSSIBLE";
        }   
    }
    for(int i=0;i<n;i++){
        cin>>multiple[i];
    }
	LargestMultiple(multiple , n);
	return 0;
}
}