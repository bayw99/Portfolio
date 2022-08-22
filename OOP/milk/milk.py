from liquid import Liquid
from typing import Sequence,Set,List,Tuple,Dict
from cup import Cup

class Milk(Liquid):
    DEFAULT_THURST : float = 6.0
    CUP : float = 3.0
    
    def __init__(self, volume : float = Cup.DEFAULT_VOLUME, thurst : float = DEFAULT_THURST):
        super(Milk,self).__init__(poured = False)
        self._cup : List[Cup] = [Cup(volume)]
        self._thurst = thurst

    @property
    def thurst(self) -> float:
        return self._thurst

    @thurst.setter
    def thurst(self,value : float) -> None:
        if value < 0 or value > 1:
            raise ValueError("invalid thurst amount")
        self._thurst = value

    @property
    def cup(self) -> Cup:
        return self._cup[0]

    @property
    def empty(self) -> bool:
        ans : bool = False
        for cup in self._cup:
            ans = ans or cup.empty
        return ans

# override
    @property
    def pour(self):
        return  self.started and not self.empty and self._thurst > 0.0