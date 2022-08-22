class Liquid:
    def __init__(self, poured : bool = False):
        self._poured : bool = poured
    @property
    def started(self) -> bool:
        return self._poured

    def start(self) -> None:
        self._poured = True

    def stop(self) -> None:
        self._poured = False

    @property
    def going(self) -> bool:
        return self._poured