#pragma once
#include "prefs.h"
#include "SimpleIni.h"
#include <msclr/marshal.h>

namespace NewTextGenWForms{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
		}
		String^ marker;
		String^ defDir;
		String^ inputFile;
		String^ outputFile;
		String^ templateFile;
		String^ config;


	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	protected:
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  mainToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  preferencesToolStripMenuItem;

	private: System::Windows::Forms::Button^  generateHtml;
	private: System::Windows::Forms::Button^  saveFile;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::WebBrowser^  webBrowser1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  reloadHtml;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::ToolStripMenuItem^  openFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::TabPage^  tabPage2;
			this->generateHtml = (gcnew System::Windows::Forms::Button());
			this->saveFile = (gcnew System::Windows::Forms::Button());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->webBrowser1 = (gcnew System::Windows::Forms::WebBrowser());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->reloadHtml = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mainToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->preferencesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			tabPage2 = (gcnew System::Windows::Forms::TabPage());
			tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabPage2
			// 
			tabPage2->AllowDrop = true;
			tabPage2->AutoScroll = true;
			tabPage2->BackColor = System::Drawing::Color::Transparent;
			tabPage2->Controls->Add(this->generateHtml);
			tabPage2->Controls->Add(this->saveFile);
			tabPage2->Controls->Add(this->splitContainer1);
			tabPage2->Controls->Add(this->reloadHtml);
			tabPage2->Location = System::Drawing::Point(4, 22);
			tabPage2->Name = L"tabPage2";
			tabPage2->Padding = System::Windows::Forms::Padding(3);
			tabPage2->Size = System::Drawing::Size(936, 561);
			tabPage2->TabIndex = 1;
			tabPage2->Text = L"Робота з файлами";
			// 
			// generateHtml
			// 
			this->generateHtml->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->generateHtml->Location = System::Drawing::Point(620, 521);
			this->generateHtml->Name = L"generateHtml";
			this->generateHtml->Size = System::Drawing::Size(108, 23);
			this->generateHtml->TabIndex = 5;
			this->generateHtml->Text = L"Generate HTML";
			this->generateHtml->UseVisualStyleBackColor = true;
			// 
			// saveFile
			// 
			this->saveFile->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->saveFile->Location = System::Drawing::Point(432, 521);
			this->saveFile->Name = L"saveFile";
			this->saveFile->Size = System::Drawing::Size(75, 23);
			this->saveFile->TabIndex = 4;
			this->saveFile->Text = L"Save File";
			this->saveFile->UseVisualStyleBackColor = true;
			this->saveFile->Click += gcnew System::EventHandler(this, &MyForm::saveFile_Click);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->splitContainer1->Location = System::Drawing::Point(3, 3);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->webBrowser1);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->richTextBox1);
			this->splitContainer1->Size = System::Drawing::Size(930, 512);
			this->splitContainer1->SplitterDistance = 463;
			this->splitContainer1->TabIndex = 2;
			// 
			// webBrowser1
			// 
			this->webBrowser1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->webBrowser1->Location = System::Drawing::Point(0, 0);
			this->webBrowser1->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser1->Name = L"webBrowser1";
			this->webBrowser1->Size = System::Drawing::Size(463, 512);
			this->webBrowser1->TabIndex = 0;
			// 
			// richTextBox1
			// 
			this->richTextBox1->AcceptsTab = true;
			this->richTextBox1->AutoWordSelection = true;
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->EnableAutoDragDrop = true;
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(463, 512);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			this->richTextBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::richTextBox1_TextChanged);
			// 
			// reloadHtml
			// 
			this->reloadHtml->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->reloadHtml->Location = System::Drawing::Point(215, 521);
			this->reloadHtml->Name = L"reloadHtml";
			this->reloadHtml->Size = System::Drawing::Size(75, 23);
			this->reloadHtml->TabIndex = 1;
			this->reloadHtml->Text = L"Reload";
			this->reloadHtml->UseVisualStyleBackColor = true;
			this->reloadHtml->Click += gcnew System::EventHandler(this, &MyForm::reloadHtml_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->mainToolStripMenuItem,
					this->preferencesToolStripMenuItem, this->aboutToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(944, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// mainToolStripMenuItem
			// 
			this->mainToolStripMenuItem->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->mainToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->openFileToolStripMenuItem,
					this->toolStripSeparator1, this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, this->toolStripSeparator2, this->exitToolStripMenuItem
			});
			this->mainToolStripMenuItem->Name = L"mainToolStripMenuItem";
			this->mainToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->mainToolStripMenuItem->Text = L"Файл";
			// 
			// openFileToolStripMenuItem
			// 
			this->openFileToolStripMenuItem->Name = L"openFileToolStripMenuItem";
			this->openFileToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->openFileToolStripMenuItem->Text = L"Open File";
			this->openFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openFileToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(121, 6);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->saveAsToolStripMenuItem->Text = L"Save As";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::saveAsToolStripMenuItem_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(121, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(124, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::exitToolStripMenuItem_Click);
			// 
			// preferencesToolStripMenuItem
			// 
			this->preferencesToolStripMenuItem->Name = L"preferencesToolStripMenuItem";
			this->preferencesToolStripMenuItem->Size = System::Drawing::Size(101, 20);
			this->preferencesToolStripMenuItem->Text = L"Налаштування";
			this->preferencesToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::preferencesToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(99, 20);
			this->aboutToolStripMenuItem->Text = L"Про програму";
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::Transparent;
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(936, 561);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Головна";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(213, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"DEG";
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button1->Location = System::Drawing::Point(301, 520);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(122, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button2->Location = System::Drawing::Point(497, 520);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(122, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(tabPage2);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 24);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(944, 587);
			this->tabControl1->TabIndex = 3;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(944, 611);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MinimumSize = System::Drawing::Size(660, 450);
			this->Name = L"MyForm";
			this->Text = L"TextGen";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			tabPage2->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void saveAsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

	saveFileDialog1->ShowDialog();
}
private: System::Void openFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->ShowDialog();
	richTextBox1->Text = File::ReadAllText(openFileDialog1->FileName, System::Text::Encoding::GetEncoding(65001));
	webBrowser1->ScriptErrorsSuppressed = true;

}
private: System::Void saveToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	StreamWriter^ outFile = gcnew StreamWriter(openFileDialog1->FileName);
	outFile->WriteLine(richTextBox1->Text);
	outFile->Close();
}
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	System::Windows::Forms::DialogResult result;
	result = MessageBox::Show("Ви дійсно хочете вийти?", "Ну чому?", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

	if (result == System::Windows::Forms::DialogResult::Yes)
	{
		Application::Exit();
	}

}
private: System::Void preferencesToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	prefs^ newForm = gcnew prefs();
	newForm->Show();
}
private: System::Void saveFile_Click(System::Object^  sender, System::EventArgs^  e) {
	StreamWriter^ outFile = gcnew StreamWriter(openFileDialog1->FileName);
	outFile->WriteLine(richTextBox1->Text);
	outFile->Close();
}
private: System::Void richTextBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	
}

private: System::Void reloadHtml_Click(System::Object^  sender, System::EventArgs^  e) {
	webBrowser1->Refresh();
}


private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	//if (iniLoad() == -1) {
	//	webBrowser1->DocumentText = createTemplate();
	//}
	//else {

	//}

	newP(1);
}



	
private: int generateNow() {
		long iter = -1;
		array<String^>^ tmpArr = gcnew array<String^>(richTextBox1->Lines->Length);
		tmpArr = richTextBox1->Lines;
		array<Char>^ charsToTrim = { L' ', L'/', L'{', L'}', L'~', L'%'};

		String^ res = tmpArr[++iter]->Trim(charsToTrim);
		
		while (tmpArr) {
						
			if (res->Contains("{")) {
				res = tmpArr[++iter]->Trim(charsToTrim);
				putTitleToHtml(res, iter);
			}
			else if (res->Contains("~")) {

				res = tmpArr[++iter]->Trim(charsToTrim);
			}

		}
		return 0;
	}
private: System::Void putTitleToHtml(String^ &x, long i) {
		HtmlElement^ acrd = webBrowser1->Document->GetElementById("accordion");
		HtmlElement^ a_headPanel = acrd->GetElementsByTagName("div")[0]->GetElementsByTagName("div")[0]->GetElementsByTagName("h4")[0]->GetElementsByTagName("a")[0];
		a_headPanel->InnerText = x;
	}

private: System::Void newP( long i) {
	String^ collapseId = String::Concat("collapse", i);
	HtmlElement^ acrd = webBrowser1->Document->GetElementById("accordion");

	//newpanel
	HtmlElement^ newPanel = acrd->Document->CreateElement("div");
	newPanel->SetAttribute("class", "panel panel-default");
	acrd->AppendChild(newPanel);

	//panelheading
	HtmlElement^ panelH = newPanel->Document->CreateElement("div");
	panelH->SetAttribute("class", "panel-heading");
	newPanel->AppendChild(panelH);

	//paneltitle
	HtmlElement^ panelT = panelH->Document->CreateElement("h4");
	panelT->SetAttribute("class", "panel-title");
	panelH->AppendChild(panelT);

	//panel-a
	HtmlElement^ panelA = panelT->Document->CreateElement("a");
	panelA->SetAttribute("data-toggle", "collapse");
	panelA->SetAttribute("parent", "#accordion");
	panelA->SetAttribute("href", String::Concat("#",collapseId));
	panelA->InnerText = "NAME";
	panelT->AppendChild(panelA);

	//////////////name


	//collapse
	HtmlElement^ panelColl = newPanel->Document->CreateElement("div");
	panelColl->SetAttribute("class", "panel-collapse collapse");
	panelColl->SetAttribute("id", collapseId);
	newPanel->AppendChild(panelColl);

	//panel
	HtmlElement^ panelB = panelColl->Document->CreateElement("div");
	panelB->SetAttribute("class", "panel-body");
	panelColl->AppendChild(panelB);

	//vars
	HtmlElement^ panelV = panelB->Document->CreateElement("div");
	panelV->SetAttribute("class", "coll-sm-2");
	panelV->InnerText = "quest";
	panelB->AppendChild(panelV);
	
	webBrowser1->Document->Body->AppendChild(acrd);
	///////////////ques
}
private: int iniLoad() {
	CSimpleIniA ini;
	msclr::interop::marshal_context ctx;
	marker = "/*mark*/";
	defDir = "./TextGen_resource/"; 

	templateFile = String::Copy(defDir);
	templateFile += "template.html";
	inputFile = String::Copy(defDir);
	inputFile += "tests.txt";
	outputFile = String::Copy(defDir);
	outputFile += "index.html";
	config = String::Copy(defDir);
	config += "config.ini";

	if (ini.LoadFile(ctx.marshal_as<const char*>(config)) == 0) {
		marker = Convert::ToString(ini.GetValue("Main", "Marker", NULL));
		inputFile = Convert::ToString(ini.GetValue("Main", "InputFile", NULL));
		templateFile = Convert::ToString(ini.GetValue("Main", "TemplateFile", NULL));
		outputFile = Convert::ToString(ini.GetValue("Main", "OutputFile", NULL));
		defDir = Convert::ToString(ini.GetValue("Main", "DefaultDirectory", NULL));
		return 0;
	}
	else {
		ini.SetValue("Main", "Marker", ctx.marshal_as<const char*>(marker));
		ini.SetValue("Main", "DefaultDirectory", ctx.marshal_as<const char*>(defDir));
		ini.SetValue("Main", "InputFile", ctx.marshal_as<const char*>(inputFile));
		ini.SetValue("Main", "OutputFile", ctx.marshal_as<const char*>(outputFile));
		ini.SetValue("Main", "TemplateFile", ctx.marshal_as<const char*>(templateFile));
		ini.SaveFile(ctx.marshal_as<const char*>(config));
		return -1;
	}
}
private: String^ createTemplate() {
	String^ str;

	str += "<!DOCUMENT html>\n";
	str += "\n";
	str += "<html>\n";
	str += "<head>\n";
	str += "	<meta http-equiv=\"X - UA - Compatible\" content=\"IE = edge\" />\n";
	str += "	<meta charset = \"windows-1251\">\n";
	str += "	<meta name = \"viewport\" content = \"width=device-width, initial-scale=1\">\n";
	str += "	<link rel = \"stylesheet\" href = \"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css \">\n";
	str += "	<script src = \"https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js \"></script>\n";
	str += "	<script src = \"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js \"></script>\n";
	str += "\n";
	str += "	<style type = \"text/css\">\n";
	str += "		.col-sm-2 {\n";
	str += "			overflow: auto;\n";
	str += "			margin: 5px;\n";
	str += "			border: #adadae;\n";
	str += "			border-width: 2px;\n";
	str += "			border-style: solid;\n";
	str += "		}\n";
	str += "\n";
	str += "		a:focus {\n";
	str += "			text-decoration: none;\n";
	str += "		}\n";
	str += "		.center{\n";
	str += "			text-align: center;\n";
	str += "		}\n";
	str += "\n";
	str += "	</style>\n";
	str += "\n";
	str += "<title>TESTS</title>\n";
	str += "</head>\n";
	str += "<body>\n";
	str += "\n";
	str += "<div class = \"container-fluid\">\n";
	str += "	<div class = \"row\">\n";
	str += "		<div class = \"container\">\n";
	str += "				<div class = \"container\">\n";
	str += "			<h2 class=\"center\">TESTS</h2>\n";
	str += "					<div class = \"panel-group\" id = \"accordion\">\n";
	str += "						<div class = \"panel panel-default\">\n";
	str += "							<div class = \"panel-heading\">\n";
	str += "								<h4 class = \"panel-title\">\n";
	str += "									<a data-toggle = \"collapse\" data-parent = \"#accordion\" href = \"#collapseX\"> </a>\n";
	str += "								</h4>\n";
	str += "							</div>\n";
	str += "\n";
	str += "						<div id = \"collapseX\" class = \"panel-collapse collapse\">\n";
	str += "							<div class = \"panel-body\">\n";
	str += "								<div class = \"col-sm-2\"></div>\n";
	str += "								<div class = \"col-sm-2\"></div>\n";
	str += "								<div class = \"col-sm-2\"></div>\n";
	str += "								<div class = \"col-sm-2\"></div>\n";
	str += "								<div class = \"col-sm-2\"></div>\n";
	str += "							</div>\n";
	str += "						</div>\n";
	str += "					</div>\n";
	str += "				</div>\n";
	str += "			</div>\n";
	str += "		</div>\n";
	str += "	</div>\n";
	str += "</div>\n";
	str += "</body>\n";
	str += "</html>\n";

	return str;
}
};
}