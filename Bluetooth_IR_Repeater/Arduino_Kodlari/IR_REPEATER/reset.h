void RESET() {
  void(* resetFunc) (void) = 0;
  resetFunc();
}
