#include <stdio.h>
#include <unistd.h>

////////////////////////////////////////////////////////////// function utils
//////////////////////////////////////////////////////////////////////////////////

typedef struct nber_struct
{
	int						number;
	int						error;
}							t_number;

t_number	ft_patoi(char *s)
{
	int			max;
	t_number	output;

	int i, n, sign;
	max = 2147483647;
	output.error = 1;
	output.number = i = n = 0;
	sign = 1;
	printf("from ft_patoi, number to process  is |%s|\n", s);
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (s[i] != '\0' && s[i] != ' ')
	{
		printf("from ft_patoi, current char  is |%c|\n", s[i]);
		if (((n > (max - (int)(s[i] - '0')) / 10) && sign == 1) || ((n > (max
						- (int)(s[i] - '1')) / 10) && sign == -1) || (s[i] < 48
				|| s[i] > 57))
		{
			printf("from ft_patoi, error case :  ccurrent char  is |%c|\n",
				s[i]);
			return (output);
		}
		n = n * 10 + (int)(s[i] - '0');
		i++;
	}
	printf("from ft_patoi, output number is |%d|\n", output.number);
	output.number = sign * n;
	output.error = 0;
	return (output);
}

int	ft_strcmp_space(char *s1, char *s2)
{
	int i, j;
	i = j = 0;
	if (!s1 || !s2)
		return (0);
	while (s2[i] != '\0')
	{
		if (s1[i] != s2[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}

char	*get_strat_selector(char *s)
{
	int		i;
	char	*strats[5] = {"--simple", "--medium", "--complex", "--adaptive", 0};

	i = 0;
	printf("== FROM get_strat_selector ==, s passed is :%s\n", s);
	while (strats[i] != 0)
	{
		if (ft_strcmp_space(s, strats[i]) == 1)
		{
			return (strats[i]);
		}
		i++;
	}
	return (NULL);
}

char	*get_bench_selector(char *s)
{
	int		i;
	char	*bench;

	bench = "--bench";
	i = 0;
	printf("== FROM get_bench_selector ==, s passed is :%s\n", s);
	if (ft_strcmp_space(s, bench) == 1)
	{
		return (bench);
	}
	return (NULL);
}

// char	*get_strat_selector(char *s)
// {
// 	int		i;
// 	char	*strats[5] = {"--simple", "--medium", "--complex", "--adaptive", 0};

// 	i = 0;
// 	printf("== FROM get_number ==, s passed is :%s\n", s);
// 	while (strats[i] != 0)
// 	{
// 		if (ft_strcmp_space(s, strats[i]) == 1)
// 		{
// 			return (strats[i]);
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 0) Enum to track names of all different states
typedef enum state_name
{
	InStart,
	InDash,
	InOption,
	InSpace,
	InInvalid,
	InNumber,
	InSuccess
}							e_state_name;

const char	*get_state_name(e_state_name enum_name)
{
	const char	*statesNames[] = {"InStartState", "InDashState",
			"InOptionState", "InSpaceState", "InInvalidState", "InNumberState",
			"InSuccessState"};

	return (statesNames[enum_name]);
}

// 1) Context
typedef struct s_interface	stateInterface;
typedef struct s_ctx
{
	stateInterface			*interface;
	e_state_name			name_state;
	char					*mystring;
	char					*addr_first_dash;
	char					*start_number;
	int						nber_digits;
	char					*option_found;
	int						candidate_number;
	char					*bench_found;
	int						nber_dash;
}							contextState;

// 2) State Interface
struct						s_interface
{
	void					(*handler_letter)(contextState *);
	void					(*handler_space)(contextState *);
	void					(*handler_digit)(contextState *);
	void					(*handler_dash)(contextState *);
	void					(*handler_other)(contextState *);
	void					(*handler_end)(contextState *);
};

// function only when i exit from option
int	extract_option_in_state(contextState *currState)
{
	char	*candidate_option;

	candidate_option = get_strat_selector(currState->addr_first_dash);
	if (!currState->option_found && candidate_option)
	{
		currState->option_found = candidate_option;
		printf("option found is  : %s\n", currState->option_found);
		return (1);
	}
	else
		return (0);
}

int	extract_bench_in_state(contextState *currState)
{
	char	*candidate_bench;

	candidate_bench = get_bench_selector(currState->addr_first_dash);
	if (!currState->bench_found && candidate_bench)
	{
		currState->bench_found = candidate_bench;
		printf("option found is  : %s\n", currState->bench_found);
		return (1);
	}
	else
		return (0);
}

// extract number in state
// t_number	extract_number_in_state(contextState *currState)
// {
// 	int			candidate_number;
// 	t_number	result;

// 	printf("from extract number : %d\n", currState->start_number);
// 	result = ft_patoi(currState->start_number);
// 	if (!result.error)
// 		currState->candidate_number = candidate_number;
// 	printf("number  found is  : %d\n", currState->candidate_number);
// 	return (candidate_number);
// }
// 3) Concrete States

// delarations of implementations for InStart
void						letterWhenInStart(contextState *currState);
void						spaceWhenInStart(contextState *currState);
void						digitWhenInStart(contextState *currState);
void						dashWhenInStart(contextState *currState);
void						otherWhenInStart(contextState *currState);
void						endWhenInStart(contextState *currState);
// delarations of implementations for InDash
void						letterWhenInDash(contextState *currState);
void						spaceWhenInDash(contextState *currState);
void						digitWhenInDash(contextState *currState);
void						dashWhenInDash(contextState *currState);
void						otherWhenInDash(contextState *currState);
void						endWhenInDash(contextState *currState);
// delarations of implementations for InOption
void						letterWhenInOption(contextState *currState);
void						spaceWhenInOption(contextState *currState);
void						digitWhenInOption(contextState *currState);
void						dashWhenInOption(contextState *currState);
void						otherWhenInOption(contextState *currState);
void						endWhenInOption(contextState *currState);
// delarations of implementations for InSpace
void						letterWhenInSpace(contextState *currState);
void						spaceWhenInSpace(contextState *currState);
void						digitWhenInSpace(contextState *currState);
void						dashWhenInSpace(contextState *currState);
void						otherWhenInSpace(contextState *currState);
void						endWhenInSpace(contextState *currState);
// delarations of implementations for InInvalid(
void						stayInInvalid(contextState *currState);

// delarations of implementations for InNumber
void						letterWhenInNumber(contextState *currState);
void						spaceWhenInNumber(contextState *currState);
void						digitWhenInNumber(contextState *currState);
void						dashWhenInNumber(contextState *currState);
void						otherWhenInNumber(contextState *currState);
void						endWhenInNumber(contextState *currState);

// success on InSuccess
void						toEndSuccess(contextState *currState);

stateInterface				InStartState = {&letterWhenInStart,
					&spaceWhenInStart, &digitWhenInStart, &dashWhenInStart,
					&otherWhenInStart, &endWhenInStart};
stateInterface				InDashState = {&letterWhenInDash, &spaceWhenInDash,
					&digitWhenInDash, &dashWhenInDash, &otherWhenInDash,
					&endWhenInDash};
stateInterface				InOptionState = {&letterWhenInOption,
					&spaceWhenInOption, &digitWhenInOption, &dashWhenInOption,
					&otherWhenInOption, &endWhenInOption};
stateInterface				InSpaceState = {&letterWhenInSpace,
					&spaceWhenInSpace, &digitWhenInSpace, &dashWhenInSpace,
					&otherWhenInSpace, &endWhenInSpace};
stateInterface				InInvalidState = {&stayInInvalid};
stateInterface				InNumberState = {&letterWhenInNumber,
					&spaceWhenInNumber, &digitWhenInNumber, &dashWhenInNumber,
					&otherWhenInNumber, &endWhenInNumber};
stateInterface				InSuccessState = {&toEndSuccess};
// transitions
void	toStartState(contextState *currState)
{
	e_state_name	enum_name;

	enum_name = InStart;
	currState->interface = &InStartState;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}

void	toInDashState(contextState *currState)
{
	e_state_name	enum_name;

	enum_name = InDash;
	currState->interface = &InDashState;
	currState->name_state = enum_name;
	currState->nber_dash += 1;
	currState->nber_digits = 0;
}

void	toInOptionState(contextState *currState)
{
	e_state_name	enum_name;

	enum_name = InOption;
	currState->interface = &InOptionState;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}

void	toInSpaceState(contextState *currState)
{
	e_state_name	enum_name;

	enum_name = InSpace;
	currState->interface = &InSpaceState;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}

void	toInInvalidState(contextState *currState)
{
	e_state_name	enum_name;

	enum_name = InInvalid;
	currState->interface = &InInvalidState;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}

void	toInNumberState(contextState *currState)
{
	e_state_name	enum_name;

	enum_name = InNumber;
	currState->interface = &InNumberState;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits += 1;
}

void	toEndSuccess(contextState *currState)
{
	e_state_name	enum_name;

	enum_name = InSuccess;
	currState->interface = &InSuccessState;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}

// In Start
void	letterWhenInStart(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", currState->name_state);
	toInInvalidState(currState);
	printf("current state is : %s\n", currState->name_state);
	printf("============================================\n");
}

void	otherWhenInStart(contextState *currState)
{
	letterWhenInStart(currState);
}

void	spaceWhenInStart(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInSpaceState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	digitWhenInStart(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInNumberState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	dashWhenInStart(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInDashState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	endWhenInStart(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("end has been reached : END OF PROGRAM\n");
	toEndSuccess(currState);
	printf("============================================\n");
}

// In InDash
void	letterWhenInDash(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInOptionState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	otherWhenInDash(contextState *currState)
{
	letterWhenInStart(currState);
}

void	spaceWhenInDash(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	digitWhenInDash(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	if (currState->nber_dash == 1)
	{
		currState->start_number = currState->addr_first_dash;
		toInNumberState(currState);
		currState->nber_dash = 0;
	}
	else if (currState->nber_dash == 0)
	{
		currState->start_number;
		toInNumberState(currState);
		currState->nber_dash = 0;
	}
	else
		toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	// reset dash counter to 0
	printf("============================================\n");
}

void	dashWhenInDash(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	if (currState->nber_dash < 2)
	{
		toInDashState(currState);
	}
	else
		toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	endWhenInDash(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("============================================\n");
}
// In OptionState
void	letterWhenInOption(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInOptionState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	otherWhenInOption(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	spaceWhenInOption(contextState *currState)
{
	char	*option_found;
	int		is_option_found;
	int		is_bench_found;

	is_option_found = -1;
	is_bench_found = -1;
	printf("============================================\n");
	is_option_found = extract_option_in_state(currState);
	is_bench_found = extract_bench_in_state(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	if (is_option_found == 0 && is_bench_found == 0)
	{
		toInInvalidState(currState);
	}
	else
	{
		toInSpaceState(currState);
	}
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
	// verify option
}

void	digitWhenInOption(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	dashWhenInOption(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	if (currState->nber_dash != 2)
		toInInvalidState(currState);
	else
		toInDashState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	endWhenInOption(contextState *currState)
{
	char	*option_found;
	int		is_option_found;
	int		is_bench_found;

	is_option_found = -1;
	is_bench_found = -1;
	printf("============================================\n");
	is_option_found = extract_option_in_state(currState);
	is_bench_found = extract_bench_in_state(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	if (is_option_found == 0 && is_bench_found == 0)
	{
		toInInvalidState(currState);
	}
	else if (!currState->option_found)
	{
		toInInvalidState(currState);
	}
	else
		toEndSuccess(currState);
	printf("end has been reached : END OF PROGRAM\n");
	printf("============================================\n");
}

// In SpaceState
void	letterWhenInSpace(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	otherWhenInSpace(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	spaceWhenInSpace(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInSpaceState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	digitWhenInSpace(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInNumberState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	dashWhenInSpace(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInDashState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	endWhenInSpace(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("end has been reached : END OF PROGRAM\n");
	toEndSuccess(currState);
	printf("============================================\n");
}
// In InNumberState
void	letterWhenInNumber(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	otherWhenInNumber(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

// void	spaceWhenInNumber(contextState *currState)
// {
// 	printf("============================================\n");
// 	printf("current state is : %s\n", get_state_name(currState->name_state));
// 	toInSpaceState(currState);
// 	printf("current state is : %s\n", get_state_name(currState->name_state));
// 	printf("============================================\n");
// }

void	spaceWhenInNumber(contextState *currState)
{
	t_number	result;

	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("from spaceWhenInNumber, start number is  : %s\n",
		currState->start_number);
	result = ft_patoi(currState->start_number);
	if (!result.error)
	{
		currState->candidate_number = result.number;
		toInSpaceState(currState);
		printf("number found after a space : %d\n", result.number);
	}
	else
		toInInvalidState(currState);
	// add number to linked list
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	digitWhenInNumber(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInNumberState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	dashWhenInNumber(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	endWhenInNumber(contextState *currState)
{
	t_number	result;

	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("from endWhenInNumber, number as string : %s\n",
		currState->start_number);
	result = ft_patoi(currState->start_number);
	if (result.error == 0)
	{
		currState->candidate_number = result.number;
		toEndSuccess(currState);
		printf("number found at the end : %d\n", result.number);
	}
	else
		toInInvalidState(currState);
	// add number to linked list
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

// In InvalidState
void	stayInInvalid(contextState *currState)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toInInvalidState(currState);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

//// implement classify_input that takes the current character of the string and return the
/// correct handler of the current state

// this is then the current handler that will hand over the current parser state to the a specific version of the handler that depends on that same given state !!

void	classify_input(contextState *mystate)
{
	char	input;

	input = *(mystate->mystring);
	if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
		return (mystate->interface->handler_letter(mystate));
	else if (input >= '0' && input <= '9')
	{
		printf("from classify_input, inpur is a number : %c\n", input);
		if (mystate->nber_digits == 0)
			mystate->start_number = mystate->mystring;
		printf("from classify_input, start_number is  : %s\n",
			mystate->start_number);
		return (mystate->interface->handler_digit(mystate));
	}
	else if (input == ' ')
		return (mystate->interface->handler_space(mystate));
	else if (input == '-')
	{
		if (mystate->nber_dash == 0)
			mystate->addr_first_dash = mystate->mystring;
		return (mystate->interface->handler_dash(mystate));
	}
	else if (input == '\0')
		return (mystate->interface->handler_end(mystate));
	else
		return (mystate->interface->handler_space(mystate));
}

contextState	*initStartState(contextState *ptr_parser)
{
	ptr_parser->interface = &InStartState;
	ptr_parser->name_state = InStart;
	ptr_parser->mystring = NULL;
	ptr_parser->addr_first_dash = NULL;
	ptr_parser->bench_found = NULL;
	ptr_parser->nber_dash = 0;
	ptr_parser->start_number = NULL;
	ptr_parser->option_found = NULL;
}

void	print_current_state(contextState *ptr_parser)
{
	printf("====== FINAL DATA IN STATE ===============\n");
	printf("current state of string is : %s\n",
		get_state_name(ptr_parser->name_state));
	printf("option  found is : %s\n", ptr_parser->option_found);
	printf("bench  found is : %s\n", ptr_parser->bench_found);
}
// int	main(void)
// {
// 	char curr_char;
// 	char *s = "2 3 5 6 ";
// 	e_state_name nameOfCurrentState;
// 	int i = 0;
// 	contextState parser;
// 	if (s != NULL)
// 		initStartState(&parser, s);
// 	printf("word to parse : %s\n", parser.addr_first_dash);
// 	while ((parser.name_state != InInvalid)
// 		&& ((parser.name_state != InSuccess)))
// 	{
// 		printf("parser.mystring : %s\n", parser.mystring);
// 		classify_input(&parser);
// 		printf("number of dash : %d\n", parser.nber_dash);
// 		parser.mystring++;
// 	}
// 	printf("out of loop current state : %s\n",
// 		get_state_name(parser.name_state));
// 	print_current_state(&parser);
// 	// if ((parser.option_found) || (parser.name_state == InInvalid))
// 	// 	printf("error");
// 	return (0);
// }

int	main(int argc, char *argv[])
{
	char			curr_char;
	e_state_name	nameOfCurrentState;
	int				i;
	contextState	parser;
	int				j;

	i = 1;
	if (argc < 2)
		return (0);
	initStartState(&parser);
	printf("word to parse : %s\n", parser.addr_first_dash);
	while (i <= argc)
	{
		parser.mystring = argv[i];
		while (*parser.mystring)
		{
			if ((parser.name_state == InInvalid)
				|| (parser.name_state == InSuccess))
			{
				printf("premature exit : %s\n",
					get_state_name(parser.name_state));
				return (0);
			}
			printf("parser.mystring : %s\n", parser.mystring);
			classify_input(&parser);
			printf("number of dash : %d\n", parser.nber_dash);
			parser.mystring++;
		}
		i++;
	}
	printf("out of loop current state : %s\n",
		get_state_name(parser.name_state));
	print_current_state(&parser);
	// if ((parser.option_found) || (parser.name_state == InInvalid))
	// 	printf("error");
	return (0);
}
