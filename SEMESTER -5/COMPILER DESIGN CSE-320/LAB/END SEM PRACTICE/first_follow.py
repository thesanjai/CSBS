from collections import defaultdict


def comp_first(grammar):
    first = defaultdict(set)
    
    def find_first(symbol):
        if symbol in first and first[symbol]:
            return first[symbol]
        if not symbol.isupper():
            return set(symbol)
        
        result = set()
        for production in grammar[symbol]:
            if production == 'ε':
                result.add('ε')
            else:
                for char in production:
                    char_first = find_first(char)
                    result.update(char_first - {'ε'})
                    if 'ε' not in char_first:
                        break
                else:
                    result.add('ε')
        
        first[symbol] = result
        return result
    
    for variable in grammar:
        find_first(variable)
    
    return dict(first)


def comp_follow(grammar, first):
    follow = defaultdict(set)
    start_symbol = next(iter(grammar))
    follow[start_symbol].add('$')
    
    while True:
        updated = False
        for lhs in grammar:
            for production in grammar[lhs]:
                trailer = follow[lhs].copy()
                for symbol in reversed(production):
                    if symbol.isupper():
                        if trailer - follow[symbol]:
                            follow[symbol].update(trailer)
                            updated = True
                        if 'ε' in first[symbol]:
                            trailer.update(first[symbol] - {'ε'})
                        else:
                            trailer = first[symbol]
                    else:
                        trailer = set(symbol)
        
        if not updated:
            break
    
    return dict(follow)


grammar = {
    "E": ["TA"],
    "A": ["+TA", "ε"],
    "T": ["FB"],
    "B": ["*FB", "ε"],
    "F": ["(E)", "d"]
}

first = comp_first(grammar)
follow = comp_follow(grammar, first)

print("First:", first)
print("Follow:", follow)