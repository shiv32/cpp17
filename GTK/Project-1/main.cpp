#include <iostream>
#include <gtkmm.h>

class HelloWindow : public Gtk::Window
{
public:
  HelloWindow()
  {
    set_title("GTKmm Example");

    set_default_size(300, 100);

    button.set_label("Click Me");

    button.signal_clicked().connect([this]
                                    { std::cout << "Button clicked " << i++ << " times" << "\n"; });

    add(button);

    show_all_children();
  }

private:
  Gtk::Button button;
  int i{0};
};

int main(int argc, char *argv[])
{
  system("clear && printf '\e[3J'"); // clean the terminal before output in linux

  auto app = Gtk::Application::create(argc, argv, "org.example.hello");

  HelloWindow window;

  return app->run(window);
}
