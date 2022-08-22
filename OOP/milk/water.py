from liquid import Liquid
from typing import Sequence,Set,List,Tuple,Dict
from cup import Cup

class Water(Liquid):
    def __init__(self, flavor : str, volume : float = Cup.DEFAULT_VOLUME):
        super(Water,self).__init__(poured = False)
        self._cup : List[Cup] = [Cup(volume)]
        self._flavor : str = flavor

    @property
    def cup(self) -> Cup:
        return self._cup[0]


    @property
    def empty(self) -> bool:
        return self.cup.empty

# override
    @property
    def pour(self):
        return  self.started