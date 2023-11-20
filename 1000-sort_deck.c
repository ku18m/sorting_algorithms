#include "deck.h"

/**
 * _strcmp -  compares two strings.
 *
 * @s1: a pointer to the first string.
 * @s2: a pointer to the second string.
 *
 * Return: (result) s1[a] - s2[a] when a difference found.
 */
int _strcmp(const char *s1, const char *s2)
{
	int a = 0, result = 0;

	while (s1[a] != '\0' && s2[a] != '\0')
	{
		if (s1[a] != s2[a])
		{
			result = (s1[a] - s2[a]);
			break;
		}
		a++;
	}
	return (result);
}

/**
 * value -  Retrieves card value.
 *
 * @value: The string representation of the card value.
 *
 * Return: The int representation of the card value or 0 if not found.
 */
int value(const char *value)
{
	value_t values[] = {
		{"Ace", 1},
		{"2", 2},
		{"3", 3},
		{"4", 4},
		{"5", 5},
		{"6", 6},
		{"7", 7},
		{"8", 8},
		{"9", 9},
		{"10", 10},
		{"Jack", 11},
		{"Queen", 12},
		{"King", 13},
		{"\0", 14}
	};
	int i;

	i = 0;
	while (!_strcmp(values[i].str, "\0"))
	{
		if (_strcmp(values[i].str, value) == 0)
		{
			return (values[i].value);
		}
		i++;
	}
	return (0);
}


/**
 * sort_kind -  Sorting card deck using insertion algorithm by kind.
 *
 * @deck: The list of nodes represents deck cards.
 */
void sort_kind(deck_node_t **deck)
{
	deck_node_t *temp, *cursor;

	cursor = *deck;

	while (cursor)
	{
		while (cursor->next && cursor->card->kind > cursor->next->card->kind)
		{
			temp = cursor->next;
			cursor->next = temp->next;
			temp->prev = cursor->prev;
			if (cursor->prev)
				cursor->prev->next = temp;
			if (temp->next)
				temp->next->prev = cursor;
			cursor->prev = temp;
			temp->next = cursor;
			if (temp->prev)
				cursor = temp->prev;
			else
				*deck = temp;
		}
		cursor = cursor->next;
	}
}

/**
 * sort_deck -  Sorting card deck using insertion algorithm.
 *
 * @deck: The list of nodes represents deck cards.
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *temp, *cursor;

	if (!deck || !(*deck)->next)
		return;

	cursor = *deck;

	/*Sorting by value*/
	while (cursor)
	{
		while (cursor->next &&
		value(cursor->card->value) > value(cursor->next->card->value))
		{
			temp = cursor->next;
			cursor->next = temp->next;
			temp->prev = cursor->prev;
			if (cursor->prev)
				cursor->prev->next = temp;
			if (temp->next)
				temp->next->prev = cursor;
			cursor->prev = temp;
			temp->next = cursor;
			if (temp->prev)
				cursor = temp->prev;
			else
				*deck = temp;
		}
		cursor = cursor->next;
	}

	sort_kind(deck);
}
