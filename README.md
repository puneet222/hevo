# hevo

#------------------------------------------------  APPROACH  --------------------------------------------------------------

<b>step 1 </b> : I made a hash function (hash*31 + char[i]) for getting    the hash value of the string.

<b>step 2 </b> : I made a structure to store key(string) and hash value of the key.
The reason for making the structure is for the function getGreaterThan and getLessThan , for that i just sort the structure by key(string) and get the
value of hash of the keys.

The above 2 steps are the main.

# Expanation of Functions

Space that I use is the string array of 10000 as HASHMAP to store and also a structure array for maintaining the key(string) and Hash value of keys.

<b>put function  void put(k,v)</b>

In put function , First i created a hash value for the key and then inserted the value at the index generated by hash function in the hm (string array).
Also I inserted the value of key(string) and hash value of key in the structure(I will tell you why soon).

TIME COMPLEXITY = O(m) (where m is size of key string for generating the hash value).

SPACE COMPLEXITY = O(m) (where m is size of key string for generating the hash value for storing the key(string) and its hash value in the structure array)




<b>get function  string get(k)</b>

In get function , first check whether the index present or not , if yes , then converting the key into HASH and returning the value at the given index.

TIME COMPLEXITY = O(1) (Just checking and returning the value).

SPACE COMPLEXITY = O(1) (No extra space used)




<b>has function  bool has(k)</b>

In has function , Converting the key(string) into hash and check the value at correspnding index whether it is NULL of not.If it is not NULL then return true.

TIME COMPLEXITY = O(1)

SPACE COMPLEXITY = O(1) (No extra space used)

<b>getGreaterThan function  String * getGreaterThan(k)</b>

In this function , I used the structures beacuse I need a track whick keys(string) are converted to hash value. I cannot compare the index(i.e. the hash value generated by the function for sorting) that is why i maintain a structure , I just have to sort the structure for a based on key(string in this case it is str).
Then getIndex function gives the index of the structure array where the key is present and from above that index I stored the value at the corresponding key(in this case it is kin variable if the structure).

TIME COMPLEXITY = O(mlog(m)) (where m is number of elements till now stored and sorting).
SPACE COMPLEXITY = O(1) (No extra space used)



<b>getLessThan function  String * getLessThan(k)</b>

Same as getGreaterThan Function

Same Complexity




<b>getNotEquals function  String * getNotEquals(k)</b>

In this function just check the jey(string) is present or not.If not then put in array.

TIME COMPLEXITY = O(m) (where m is number of elements till now stored and sorting).

SPACE COMPLEXITY = O(1) (No extra space used)
