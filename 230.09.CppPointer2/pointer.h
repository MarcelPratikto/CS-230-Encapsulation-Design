/*************************************************************
 * 1. Name:
 *      Marcel Pratikto, Grant Shirley, Spencer Lamoreaux
 * 2. Assignment Name:
 *      Practice 09: Pointer Arithmetic
 * 3. Assignment Description:
 *      Traverse a string using pointer notation
 * 4. What was the hardest part? Be as specific as possible.
 *      
 * 5. How long did it take for you to complete the assignment?
 *      
 **************************************************************/


/**************************************
 * COUNT - ARRAY
 **************************************/
int countArray(char* cString, char character)
{
	int count = 0;
	int len = strlen(cString);
	for (int i = 0; i < len; ++i)
	{
		if (cString[i] == character)
			++count;
	}
	return count;
}

/**************************************
 * COUNT - POINTER
 **************************************/
int countPointer(char* cString, char character)
{
	int count = 0;
	for (char *p = cString; *p; ++p)
	{
		if (*p == character)
			++count;
	}
	return count;
}