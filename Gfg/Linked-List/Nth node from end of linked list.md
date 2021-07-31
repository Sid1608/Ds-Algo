

### []()
Author:@Siddharth Akar<br>
Problem Statement:


## Approach1

``` cpp
int getNthFromLast(Node *head, int n)
{
	int size = 0;
	Node *temp = head;
	while (temp != NULL)
	{
		size++;
		temp = temp->next;
	}
	if (size < n)
		return -1;
	int reqpos = size - n + 1, s = 0, ans;
	while (head != NULL)
	{
		s++;
		if (s == reqpos)
		{
			ans = head->data;
			break;
		}
		head = head->next;
	}
	return ans;
}

```

## Approach2

``` cpp

```
## Approach3

``` cpp

```
## Approach4

``` cpp

```
## Approach5

``` cpp

```
