class Gpio {
public:
    Gpio() {
        // init GPIO pin
    }

    void toggle() {
        // toggle pin state
    }
};

int main() {
    Gpio gpio();  // ❗ MVP: bu bir fonksiyon bildirimi, init yapılmaz!
    // gpio.toggle(); // ❌ çalışmaz çünkü 'gpio' bir nesne değil

    Gpio gpioSafe{}; // ✅ brace initialization, init garanti
    gpioSafe.toggle();
    return 0;
}