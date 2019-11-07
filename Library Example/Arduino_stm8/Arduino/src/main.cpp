extern void __preinit();
extern void setup();
extern void loop();

void main() {
  __preinit();

  setup();
  /* Infinite loop */
  while (1) {
    loop();
  }
}
