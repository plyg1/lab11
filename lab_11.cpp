#pragma once

namespace MyApp {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent(); // Ініціалізація компонентів форми
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components; // Видалення компонентів при закритті форми
            }
        }

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::TextBox^ textBox2;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(9, 8);
            this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(135, 13);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Введіть тризначне число:"; // Підпис для введення числа
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(148, 5);
            this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(68, 20);
            this->textBox1->TabIndex = 1; // Поле для введення тризначного числа
            // 
            // button1
            // 
            this->button1->Location = System::Drawing::Point(12, 75);
            this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(173, 21);
            this->button1->TabIndex = 2;
            this->button1->Text = L"Перетворити";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click); // Кнопка для перетворення числа
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(11, 44);
            this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(93, 13);
            this->label2->TabIndex = 3;
            this->label2->Text = L"Отримане число:"; // Підпис для відображення результату
            // 
            // textBox2
            // 
            this->textBox2->Location = System::Drawing::Point(148, 37);
            this->textBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->textBox2->Name = L"textBox2";
            this->textBox2->ReadOnly = true;
            this->textBox2->Size = System::Drawing::Size(68, 20);
            this->textBox2->TabIndex = 4; // Поле для відображення отриманого числа
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FloralWhite;
            this->ClientSize = System::Drawing::Size(268, 107);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->label1);
            this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        int number;
        // Перевірка, чи є введене число тризначним
        if (Int32::TryParse(textBox1->Text, number) && number >= 100 && number <= 999) {
            int a = number / 100; // Перша цифра числа
            int bc = number % 100; // Останні дві цифри числа
            int newNumber = bc * 10 + a; // Створення нового числа з першої цифри в кінці
            textBox2->Text = newNumber.ToString(); // Виведення результату
        }
        else {
            // Виведення повідомлення про помилку, якщо введене число некоректне
            MessageBox::Show("Будь ласка, введіть коректне тризначне число!", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            textBox1->Clear(); // Очищення полів вводу
            textBox2->Clear();
        }
    }
    };
}
