#pragma once

namespace NewTextGenWForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для prefs
	/// </summary>
	public ref class prefs : public System::Windows::Forms::Form
	{
	public:
		prefs()
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~prefs()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(103, 61);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Файл з тестами";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(106, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Файл-темплейт";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(41, 138);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(152, 13);
			this->label3->TabIndex = 2;
			this->label3->Tag = L"Зазвичай це index.html";
			this->label3->Text = L"Назва згенерованого файлу";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(214, 58);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(236, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &prefs::textBox1_MouseClick);
			this->textBox1->MouseHover += gcnew System::EventHandler(this, &prefs::textBox1_MouseHover);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(214, 95);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(236, 20);
			this->textBox2->TabIndex = 4;
			this->textBox2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &prefs::textBox2_MouseClick);
			this->textBox2->MouseHover += gcnew System::EventHandler(this, &prefs::textBox2_MouseHover);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(214, 135);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(236, 20);
			this->textBox3->TabIndex = 5;
			this->textBox3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &prefs::textBox3_MouseClick);
			this->textBox3->MouseHover += gcnew System::EventHandler(this, &prefs::textBox3_MouseHover);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 175);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"За замовчуванням";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &prefs::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(331, 175);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Зберегти";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(417, 175);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Скасувати";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &prefs::button3_MouseClick);
			// 
			// toolTip1
			// 
			this->toolTip1->AutoPopDelay = 5000;
			this->toolTip1->InitialDelay = 500;
			this->toolTip1->ReshowDelay = 100;
			this->toolTip1->Tag = L"";
			this->toolTip1->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			this->toolTip1->ToolTipTitle = L"help)";
			// 
			// prefs
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(508, 224);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"prefs";
			this->Text = L"Налаштування";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void textBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	openFileDialog1->Filter = "Текстові файли|*.txt";
	openFileDialog1->ShowDialog();
	textBox1->Text = openFileDialog1->FileName;
}
private: System::Void textBox2_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	openFileDialog1->Filter = "HTML файл|*.html";
	openFileDialog1->ShowDialog();
	textBox2->Text = openFileDialog1->FileName;
}
private: System::Void textBox3_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	openFileDialog1->Filter = "HTML файл|*.html";
	openFileDialog1->ShowDialog();
	textBox3->Text = openFileDialog1->FileName;
}

private: System::Void button3_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	Close();
}
private: System::Void textBox1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		toolTip1->SetToolTip(this->textBox1, "Натисніть щоб вибрати файл");
	}
private: System::Void textBox2_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	toolTip1->SetToolTip(this->textBox2, "Натисніть щоб вибрати файл");
}
private: System::Void textBox3_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	toolTip1->SetToolTip(this->textBox3, "Натисніть щоб вибрати файл");
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	
}
};
}
