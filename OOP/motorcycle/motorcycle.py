from typing import Sequence
from gastank import Gas

class Motorcycle:
    def __init__(self, color : str, tanksize : float = Gas.DEFAULT_TANK): #dia tank
        self._gastank : Sequence[Gas] = (Gas(tanksize),Gas(tanksize))
        self._color : str = color
        self._started : bool = False

    @property
    def tank(self) -> Gas:
        return self._gastank[0]

    @property
    def empty(self) -> bool:
        return self.tank.empty

    def start(self) -> None:
        self._started = True

    def stop(self) -> None:
        self._started = False

    @property
    def started(self):
        return self._started

    @property
    def going(self):
        return  self.started and not self.empty