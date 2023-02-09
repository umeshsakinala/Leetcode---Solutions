class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        restrict = set(ideas)
        invalid = dict()
        counter = dict()
        cannot_receive = dict()
        available = []
        used = set()
        res = 0


        for idea in ideas:
            invalid[idea] = set()
            if idea[0] in used: 
                counter[idea[0]] += 1
                continue
            counter[idea[0]] = 1
            available.append(idea[0])
            used.add(idea[0])

        for x in available:
            cannot_receive[x] = dict()
            for y in available:
                cannot_receive[x][y] = 0


        for idea in ideas:
            queue = []
            for a in available:
                x = a + idea[1:]
                if a == idea[0]: continue
                if x in restrict:
                    cannot_receive[a][idea[0]] += 1
                    invalid[idea].add(a)

        for idea in ideas:
            cur = len(ideas) 
            cur -= counter[idea[0]]

            for a in available:
                if a in invalid[idea]:
                    cur -= counter[a]
                    continue
                
                cur -= cannot_receive[idea[0]][a]
                
            res += cur
            
        return res
